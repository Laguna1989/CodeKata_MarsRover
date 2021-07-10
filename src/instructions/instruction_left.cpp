#include <map>
#include "instruction_left.hpp"
#include "rover_orientation.hpp"

namespace {
    roverOrientation convert(roverOrientation const & orientation)
    {
        static std::map<roverOrientation, roverOrientation> conversion;

        conversion[NORTH] = WEST;
        conversion[WEST] = SOUTH;
        conversion[SOUTH] = EAST;
        conversion[EAST] = NORTH;

        return conversion.at(orientation);
    }
}

RoverPlacement InstructionLeft::act(RoverPlacement const& placement) {
    
    return RoverPlacement{placement.m_x, placement.m_y, convert(placement.m_orientation)};
}
