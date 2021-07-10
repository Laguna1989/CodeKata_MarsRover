#ifndef INSTRUCTIONS_INSTRUCTION_MOVE
#define INSTRUCTIONS_INSTRUCTION_MOVE

#include "instruction_interface.hpp"
#include "rover_placement.hpp"

class InstructionMove : public InstructionInterface{
public:
    RoverPlacement act(RoverPlacement const& placement) override;
};

#endif