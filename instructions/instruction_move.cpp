#include <map>
#include "instruction_move.hpp"
#include "rover_orientation.hpp"

namespace {
   
    
}

RoverPlacement InstructionMove::act(RoverPlacement const& placement) {
    
    std::map<roverOrientation, RoverPlacement> conversion;
    
    conversion[NORTH] = RoverPlacement{placement.m_x, placement.m_y + 1, NORTH};
    conversion[WEST] = RoverPlacement{placement.m_x - 1, placement.m_y, WEST};
    conversion[SOUTH] = RoverPlacement{placement.m_x, placement.m_y - 1, SOUTH};
    conversion[EAST] = RoverPlacement{placement.m_x + 1, placement.m_y, EAST};
    
    return conversion.at(placement.m_orientation);
}