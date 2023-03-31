#include "bowling.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE ("this test should pass")
{
  Bowling::Game g;
    g.setGameStatus(false);
    WHEN("strike")
    {
      g.resetBalls();
      g.resetScore();
      g.recordBall(10);
      g.recordBall(10);
      g.recordBall(10);
      g.calcScore();
      REQUIRE(g.getScore() == 30);
    }
    WHEN("spare")
    {
      g.resetBalls();
      g.resetScore();
      g.recordBall(5);
      g.recordBall(5);
      g.recordBall(3);
      g.calcScore();
      REQUIRE(g.getScore() == 13);

    }
    WHEN("Neither strike nor spare")
    {
      g.resetBalls();
      g.resetScore();
      g.recordBall(2);
      g.recordBall(3);
      g.calcScore();
      REQUIRE(g.getScore() == 5);
    }
    WHEN("No balls are recorded and exceptions is thrown")
    {
      g.resetBalls();
      g.resetScore();
      REQUIRE_THROWS(g.calcScore());
    }
}

