#ifndef INSTRUCTIONLEFT_HPP
#define INSTRUCTIONLEFT_HPP

#include "instruction_interface.hpp"
#include "rover_placement.hpp"


class InstructionLeft : public InstructionInterface
{
public:
    RoverPlacement act(RoverPlacement const& placement) override;
};

#endif