#ifndef INSTRUCTIONINTERFACE_HPP
#define INSTRUCTIONINTERFACE_HPP

#include "../rover_placement.hpp"

class InstructionInterface{
public:
    virtual ~InstructionInterface() = default;
    virtual RoverPlacement act(RoverPlacement const& placement) = 0;
};

#endif