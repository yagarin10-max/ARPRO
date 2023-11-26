#include <duels/fibo/game.h>

using namespace duels::fibo;

int main(int argc, char** argv)
{
  Game game(argc, argv, "your name");

  Input input;
  Feedback feedback;
  const auto timeout = game.timeout;

  while(game.get(feedback))
  {
    // write input in less than timeout



    game.send(input);
  }
}