#include "bowling.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE ("this test should pass")
{
  Bowling::Game g;
    g.setGameStatus(false);
    WHEN("num_pins for a rolls knocked down is 10")
    {
      g.resetBalls();
      g.recordBall(10);
      g.recordBall(10);
      g.calcScore();
      REQUIRE(g.getScore() == 30);
    }
    WHEN("pins is 5 and 5")
    {
      g.resetBalls();
      g.recordBall(5);
      g.recordBall(5);
      g.recordBall(3);
      g.calcScore();
      REQUIRE(g.getScore() == 13);

    }
}

