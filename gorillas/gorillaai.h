#ifndef GORILLAAI_H
#define GORILLAAI_H


class GorillaAI
{
public:
    GorillaAI(double, double, double);

    double p_error;
    double i_error;
    double d_error;
    double Kp;
    double Ki;
    double Kd;

    bool init_d = false;
    double prev_cte;

    void UpdateError(double cte);

    double TotalError();
};

#endif // GORILLAAI_H
