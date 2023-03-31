#pragma once
#include <vector>
namespace Bowling
{
  class Game
{
  public:
    bool g_isComplete;
    int score;
    std::vector<int> balls;
    Game()
    {
      g_isComplete = false;
      score = 0;
      balls = {};
    }
    void setGameStatus(bool status){g_isComplete = status;}
    bool isComplete(){return g_isComplete;}
    void recordBall(int num_pins)
    {
      balls.push_back(num_pins);
    }
    void resetBalls(){balls.clear();}
    void resetScore(){score = 0;}
    void calcScore(){
      if ((balls.at(0) == 10) || (balls.at(0) + balls.at(1) == 10)){  //strike or spare
        score = balls.at(0) + balls.at(1) + balls.at(2);
      }
      else{
        score = balls.at(0) + balls.at(1);
      }
    }

    int getScore(){return score;}
};
 
}

