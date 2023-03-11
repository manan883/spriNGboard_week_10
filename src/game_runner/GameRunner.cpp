#include "Game.h"

#include <string>

using namespace std;

int main(int argc, char** argv)
{
  if (argc == 1) {
    srand(time(NULL));
  }
  else {
    unsigned seed = stoi(argv[1]);
    srand(seed);
  }

  Game aGame;

  aGame.add("Chet");
  aGame.add("Pat");
  aGame.add("Sue");

  bool notAWinner = true;

  do
  {
    aGame.roll(rand() % 5 + 1);

    if (rand() % 9 == 7)
    {
      notAWinner = aGame.wrongAnswer();
    }
    else
    {
      notAWinner = aGame.wasCorrectlyAnswered();
    }
  } while (notAWinner);
}

