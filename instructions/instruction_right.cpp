#include <map>
#include "instruction_right.hpp"
#include "rover_orientation.hpp"

namespace {
    
    roverOrientation convert(roverOrientation const & orientation)
    {
        static std::map<roverOrientation, roverOrientation> conversion;

        conversion[NORTH] = EAST;
        conversion[WEST] = NORTH;
        conversion[SOUTH] = WEST;
        conversion[EAST] = SOUTH;

        return conversion.at(orientation);
    }
    
}

RoverPlacement InstructionRight::act(RoverPlacement const& placement) {
    
    return RoverPlacement{placement.m_x, placement.m_y, convert(placement.m_orientation)};
}