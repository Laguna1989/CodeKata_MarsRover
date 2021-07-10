#include <gtest/gtest.h>
#include <memory>
#include "instructions/instruction_move.hpp"

TEST(InstructionMoveTest, MoveNorth)
{
    auto instruction = std::make_shared<InstructionMove>();
    RoverPlacement initial_placement{1,1, NORTH};
    RoverPlacement expected_placement{1,2, NORTH};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}

TEST(InstructionMoveTest, MoveEAST)
{
    auto instruction = std::make_shared<InstructionMove>();
    RoverPlacement initial_placement{1,1, EAST};
    RoverPlacement expected_placement{2,1, EAST};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}

TEST(InstructionMoveTest, MoveSOUTH)
{
    auto instruction = std::make_shared<InstructionMove>();
    RoverPlacement initial_placement{1,1, SOUTH};
    RoverPlacement expected_placement{1,0, SOUTH};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}

TEST(InstructionMoveTest, MoveWEST)
{
    auto instruction = std::make_shared<InstructionMove>();
    RoverPlacement initial_placement{1,1, WEST};
    RoverPlacement expected_placement{0,1, WEST};
    
    RoverPlacement updated_placement = instruction->act(initial_placement);
    
    EXPECT_EQ(expected_placement, updated_placement);
}
