#ifndef ROVER_ORIENTATION_HPP
#define ROVER_ORIENTATION_HPP

#include<string>

enum roverOrientation{
    NORTH,
    SOUTH,
    EAST,
    WEST
};

roverOrientation convert_orientation(std::string const &input);

std::string orientation_to_string(roverOrientation const& roverOrientation);

#endif