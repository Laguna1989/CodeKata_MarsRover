#include "rover_data.hpp"

bool operator== (RoverData const& lhs, RoverData const& rhs)
{
    return lhs.m_placement == rhs.m_placement && lhs.m_instructions == rhs.m_instructions;
}
