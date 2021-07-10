#include "convert_instructions.hpp"
#include "instruction_left.hpp"
#include "instruction_right.hpp"
#include "instruction_move.hpp"

std::vector<std::shared_ptr<InstructionInterface>> convert_instructions(std::string const& input)
{
    std::vector<std::shared_ptr<InstructionInterface>> return_vector;
    
    for( auto const c: input )
    {
        if (c == 'L')
        {
            return_vector.push_back(std::make_shared<InstructionLeft>());
        }
        if (c == 'R')
        {
            return_vector.push_back(std::make_shared<InstructionRight>());
        }
        if (c == 'M')
        {
            return_vector.push_back(std::make_shared<InstructionMove>());
        }
    }
    return return_vector;
}