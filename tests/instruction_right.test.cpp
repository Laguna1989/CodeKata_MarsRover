#include <gtest/gtest.h>
#include <memory>
#include "instructions/instruction_right.hpp"

TEST(InstructionRightTest, Turns90DegreeRightFromNorth)
{
    auto instruction = std::make_shared<InstructionRight>();
    RoverPlacement initial_placement{1,1, NORTH};
    RoverPlacement expected_placement{1,1, EAST};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}

TEST(InstructionRightTest, Turns90DegreeRightFromEast)
{
    auto instruction = std::make_shared<InstructionRight>();
    RoverPlacement initial_placement{1,1, EAST};
    RoverPlacement expected_placement{1,1, SOUTH};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}

TEST(InstructionRightTest, Turns90DegreeRightFromEastDifferentPosition)
{
    auto instruction = std::make_shared<InstructionRight>();
    RoverPlacement initial_placement{2,1, EAST};
    RoverPlacement expected_placement{2,1, SOUTH};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}

TEST(InstructionRightTest, Turns90DegreeRightFromSouth)
{
    auto instruction = std::make_shared<InstructionRight>();
    RoverPlacement initial_placement{2,4, SOUTH};
    RoverPlacement expected_placement{2,4, WEST};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}
