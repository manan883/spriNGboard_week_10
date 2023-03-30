#include "bowling.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE ("this test should pass")
{
  Bowling::Game g;
  REQUIRE(g.isComplete() == true);
}

