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
    void calcScore(){
      score = 30;
    }
    int getScore(){return score;}
};
 
}

