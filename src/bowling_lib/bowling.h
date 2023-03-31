#pragma once
#include <vector>
#include <stdexcept>
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
      if ((balls.size() <=1) || (balls.size() >3))     
      {
        throw std::logic_error("Must record balls before calculating scores");
      }
      if ((balls.at(0) == 10) || (balls.at(0) + balls.at(1) == 10)){  //strike or spare
        if ((balls.at(0) < 0) ||(balls.at(1) < 0) || (balls.at(2) < 0)){
          throw std::logic_error("no negative numbers");
        }
        else{
            score = balls.at(0) + balls.at(1) + balls.at(2);
        }
      }
      else if((balls.at(0) + balls.at(1) <= 10) && ((balls.at(0) + balls.at(1) >= 0) )) {
        if ((balls.at(0) < 0) ||(balls.at(1) < 0)){
          throw std::logic_error("no negative numbers");
        }
        else{
          score = balls.at(0) + balls.at(1);
        }

      }
      else{
         throw std::logic_error("SOME BALL RECORDING ERROR");

      }
    }

    int getScore(){return score;}
};
 
}

