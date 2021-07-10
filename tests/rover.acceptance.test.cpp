#include "mars_rover.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(MarsRoverAcceptanceTest, bossmonster)
{
    auto const input = 
R"foo(5 5
1 2 N
LMLMLMLMM
3 3 E
MMRMMRMRRM)foo";
    
    auto const expected_output = 
R"foo(1 3 N
5 1 E)foo";
    
    auto const output = mars_rover(input);
    EXPECT_EQ(expected_output, output);
}

