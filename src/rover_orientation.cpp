#include "rover_orientation.hpp"

roverOrientation convert_orientation(std::string const &input)
{
    if (input == "E")
    {
        return EAST;
    }
    if (input == "S")
    {
        return SOUTH;
    }
    if (input == "W")
    {
        return WEST;
    }
    return NORTH;
}

std::string orientation_to_string(roverOrientation const& roverOrientation)
{
    if (roverOrientation == EAST)
    {
        return "E";
    }
    if (roverOrientation == SOUTH)
    {
        return "S";
    }
    if (roverOrientation == WEST)
    {
        return "W";
    }
    return "N";
}