#ifndef ROVER_DATA_HPP
#define ROVER_DATA_HPP

#include "rover_placement.hpp"

typedef struct {
    RoverPlacement m_placement;
    std::string m_instructions;
} RoverData;

bool operator== (RoverData const& lhs, RoverData const& rhs);

#endif