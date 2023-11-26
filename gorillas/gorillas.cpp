#include <duels/gorillas/game.h>
#include "gorillaai.h"

using namespace duels::gorillas;

int main(int argc, char** argv)
{
  Game game(argc, argv, "Your name here", 2);   // difficulty from 0 to 3

  Input input;
  Feedback feedback;
  const auto timeout = game.timeout_ms();

  input.angle = 60;
  input.vel = 50;
  int vel_min = 10;
  int vel_max = 300;
  double adjust = -0.1;
  GorillaAI pid(1,0.01,0);

  while(game.get(feedback))
  {    
    // write input in less than timeout

    auto x_err = feedback.opponent.x - feedback.banana.x;
    std::cout << x_err << std::endl;
    pid.UpdateError(x_err);
    double f_err = pid.TotalError();
    std::cout << f_err << std::endl;

    input.vel += f_err * adjust;
    if (input.vel < vel_min) input.vel = vel_min;
    if (input.vel > vel_max) input.vel = vel_max;
    std::cout << input.vel << std::endl;

    game.send(input);
  }
}
