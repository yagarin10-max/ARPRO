#ifndef GORILLAAI_H
#define GORILLAAI_H

#include <duels/gorillas/msg.h>
using namespace duels::gorillas;

class GorillaAI
{
public:
    GorillaAI(double, double, double, double, double);

    double p_error=0.0;
    double i_error=0.0;
    double d_error=0.0;
    double Kp;
    double Ki;
    double Kd;
    double pre_vel;
    double pre_angle;
    bool first = false;

    bool init_d = false;
    double prev_cte;

    void UpdateError(double cte);
    Input computeFrom(const Feedback &feedback);
    double TotalError();
};

#endif // GORILLAAI_H
