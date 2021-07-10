#ifndef ROVER_PLACEMENT_HPP
#define ROVER_PLACEMENT_HPP

#include "rover_orientation.hpp"

typedef struct {
    int m_x;
    int m_y;
    roverOrientation m_orientation;
} RoverPlacement;

bool operator== (RoverPlacement const& lhs, RoverPlacement const& rhs);

#endif