#include "rover_placement.hpp"

bool operator==(const RoverPlacement& lhs, const RoverPlacement& rhs)
{
    return lhs.m_x == rhs.m_x &&
           lhs.m_y == rhs.m_y &&
           lhs.m_orientation == rhs.m_orientation;
}