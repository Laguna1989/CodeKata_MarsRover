#include <gtest/gtest.h>
#include <typeinfo>
#include <memory>
#include <vector>
#include "instructions/convert_instructions.hpp"
#include "instructions/instruction_left.hpp"
#include "instructions/instruction_right.hpp"
#include "instructions/instruction_move.hpp"

TEST(ConvertInstructionsTest, SingleInstructionL)
{
    std::string const input = "L";
    
    std::vector<std::shared_ptr<InstructionInterface>> instructions = convert_instructions(input);

    EXPECT_NE(nullptr, dynamic_cast<InstructionLeft*>(instructions.front().get()));
}

TEST(ConvertInstructionsTest, SingleInstructionR)
{
    std::string const input = "R";
    
    std::vector<std::shared_ptr<InstructionInterface>> instructions = convert_instructions(input);

    EXPECT_NE(nullptr, dynamic_cast<InstructionRight*>(instructions.front().get()));
}

TEST(ConvertInstructionsTest, SingleInstructionM)
{
    std::string const input = "M";
    
    std::vector<std::shared_ptr<InstructionInterface>> instructions = convert_instructions(input);

    EXPECT_NE(nullptr, dynamic_cast<InstructionMove*>(instructions.front().get()));
}

TEST(ConvertInstructionsTest, MultipleInstructions)
{
    std::string const input = "MLR";
    
    std::vector<std::shared_ptr<InstructionInterface>> instructions = convert_instructions(input);

    EXPECT_NE(nullptr, dynamic_cast<InstructionMove*>(instructions.at(0).get()));
    EXPECT_NE(nullptr, dynamic_cast<InstructionLeft*>(instructions.at(1).get()));
    EXPECT_NE(nullptr, dynamic_cast<InstructionRight*>(instructions.at(2).get()));
}
