#include "input_parser.hpp"

namespace{
    PlateauSize parse_plateau_size(std::stringstream& stream)
    {
        PlateauSize plateau_size;
        stream >> plateau_size.m_width >> plateau_size.m_height;
        
        return plateau_size;
    }
    
    RoverPlacement parsePlacement(std::stringstream& stream)
    {
        RoverPlacement placement;
        stream >> placement.m_x;
        stream >> placement.m_y;
        std::string temp;
        stream >> temp;
        placement.m_orientation = convert_orientation(temp);
        
        return placement;
    }
    
    RoverData parse_rover_data(std::stringstream& stream)
    {
        RoverData rover_data;
        rover_data.m_placement = parsePlacement(stream);
        
        stream >> rover_data.m_instructions;
        
        return rover_data;
    }
}

bool parse(std::string const& input, RemoteCommandData& data)
{
    if (input.empty())
    {
        return false;
    }
    std::stringstream stream(input);
    
    data.m_plateau_size = parse_plateau_size(stream);
    
    while ( true )
    {
        if (stream.fail()) {
            break;
        } else if (stream.eof()) {
            break;
        }
        RoverData rover_data = parse_rover_data(stream);
        data.m_all_rover_data.push_back(rover_data);
        
    }
    
    return !stream.fail();
}


bool operator==(PlateauSize const& lhs, PlateauSize const& rhs)
{
    return lhs.m_width == rhs.m_width
        && lhs.m_height == rhs.m_height;
}