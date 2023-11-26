#include "gorillaai.h"

GorillaAI::GorillaAI(double Kp_, double Ki_, double Kd_)
{
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
}

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
  return -Kp*p_error - Ki*i_error - Kd*d_error;
}
