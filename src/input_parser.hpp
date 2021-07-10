#ifndef INPUT_PARSER_HPP
#define INPUT_PARSER_HPP

#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include "rover_orientation.hpp"
#include "rover_placement.hpp"
#include "rover_data.hpp"

typedef struct {
    int m_width, m_height;
} PlateauSize;
bool operator==(PlateauSize const& lhs, PlateauSize const& rhs);

typedef struct {
    PlateauSize m_plateau_size;
    std::vector<RoverData> m_all_rover_data;
} RemoteCommandData;

bool parse(std::string const& input, RemoteCommandData& data);
roverOrientation convert_orientation(std::string const &);


#endif