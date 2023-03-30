#pragma once

namespace Bowling
{
  class Game
{
  public:
    Game(){}
    bool isComplete(){return true;}
    void recordBall(int num_pins);
    int getScore();
};
 
}

