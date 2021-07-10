#include <gtest/gtest.h>
#include "rover_orientation.hpp"

using namespace ::testing;

TEST(RoverOrientation, orientation_to_string_EAST)
{
    auto const input = EAST;
    auto const expected = "E";
    
    EXPECT_EQ(orientation_to_string(input), expected);
}

TEST(RoverOrientation, orientation_to_string_WEST)
{
    auto const input = WEST;
    auto const expected = "W";
    
    EXPECT_EQ(orientation_to_string(input), expected);
}

TEST(RoverOrientation, orientation_to_string_SOUTH)
{
    auto const input = SOUTH;
    auto const expected = "S";
    
    EXPECT_EQ(orientation_to_string(input), expected);
}

TEST(RoverOrientation, orientation_to_string_NORTH)
{
    auto const input = NORTH;
    auto const expected = "N";
    
    EXPECT_EQ(orientation_to_string(input), expected);
}

TEST(RoverOrientation, convert_string_to_roverOrientation_EAST)
{
    auto const expected = EAST;
    auto const input = "E";
    
    EXPECT_EQ(convert_orientation(input), expected);
}

TEST(RoverOrientation, convert_string_to_roverOrientation_WEST)
{
    auto const expected = WEST;
    auto const input = "W";
    
    EXPECT_EQ(convert_orientation(input), expected);
}

TEST(RoverOrientation, convert_string_to_roverOrientation_SOUTH)
{
    auto const expected = SOUTH;
    auto const input = "S";
    
    EXPECT_EQ(convert_orientation(input), expected);
}

TEST(RoverOrientation, convert_string_to_roverOrientation_NORTH)
{
    auto const expected = NORTH;
    auto const input = "N";
    
    EXPECT_EQ(convert_orientation(input), expected);
}


