#include "gorillaai.h"
#include <duels/gorillas/msg.h>
using namespace duels::gorillas;

GorillaAI::GorillaAI(double Kp_, double Ki_, double Kd_, double v, double a)
{
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    pre_vel = v;
    pre_angle = a;
}

Input GorillaAI::computeFrom(const Feedback &feedback) {
    Input input;
    int vel_min = 10;
    int vel_max = 300;
    double adjust = -0.1;
    input.vel = this->pre_vel;
    input.angle = this->pre_angle;

    auto x_err = feedback.opponent.x - feedback.banana.x;

    UpdateError(x_err);
    double f_err = TotalError();
    if (!first) {
        first = true;
    } else {
        input.vel = this->pre_vel + f_err * adjust;
        if (input.vel < vel_min) input.vel = vel_min;
        if (input.vel > vel_max) input.vel = vel_max;
    }
    pre_vel = input.vel;
    std::cout << x_err << std::endl;
    std::cout << f_err << std::endl;
    std::cout << input.vel << std::endl;

    return input;
};

void GorillaAI::UpdateError(double cte) {
  if(!init_d){
    init_d = true;
    d_error = cte;
    prev_cte = cte;
  }else{
    d_error = cte - prev_cte;
    prev_cte = cte;
  }
  p_error = cte;
  i_error +=cte;
}

double GorillaAI::TotalError() {
  std::cout << "p" << p_error << "i" << i_error << "d" << d_error << std::endl;
  return -Kp*p_error - Ki*i_error - Kd*d_error;
}
