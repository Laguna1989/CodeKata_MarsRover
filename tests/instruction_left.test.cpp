#include <gtest/gtest.h>
#include <memory>
#include "instructions/instruction_left.hpp"


TEST(InstructionLeftTest, Turns90DegreeLeft)
{
    auto instruction = std::make_shared<InstructionLeft>();
    RoverPlacement initial_placement{1,1, NORTH};
    RoverPlacement expected_placement{1,1, WEST};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}

TEST(InstructionLeftTest, Turns90DegreeLeftFromEast)
{
    auto instruction = std::make_shared<InstructionLeft>();
    RoverPlacement initial_placement{1,1, EAST};
    RoverPlacement expected_placement{1,1, NORTH};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}

TEST(InstructionLeftTest, Turns90DegreeLeftFromEastDifferentPosition)
{
    auto instruction = std::make_shared<InstructionLeft>();
    RoverPlacement initial_placement{2,1, EAST};
    RoverPlacement expected_placement{2,1, NORTH};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}

TEST(InstructionLeftTest, Turns90DegreeLeftFromSouth)
{
    auto instruction = std::make_shared<InstructionLeft>();
    RoverPlacement initial_placement{2,4, SOUTH};
    RoverPlacement expected_placement{2,4, EAST};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}
