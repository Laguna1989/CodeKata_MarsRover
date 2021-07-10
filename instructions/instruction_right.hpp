#ifndef INSTRUCTIONS_INSTRUCTION_RIGHT
#define INSTRUCTIONS_INSTRUCTION_RIGHT

#include "instruction_interface.hpp"
#include "rover_placement.hpp"

class InstructionRight : public InstructionInterface{
public:
    RoverPlacement act(RoverPlacement const& placement) override;
};

#endif