// The starting files are unrelated to the exercise.
//
// They simply show syntax for writing and testing
//  o) a global function
//  o) an instance method
// Pick the style that best fits the exercise.
// Then delete the other one, along with this comment!

#include <sstream>
#include "mars_rover.hpp"
#include "input_parser.hpp"
#include "instructions/convert_instructions.hpp"

std::string mars_rover(std::string const& input)
{
    RemoteCommandData parsed_data;
    if (parse(input,parsed_data))
    {    
        for (auto& roverdata : parsed_data.m_all_rover_data)
        {
            auto const instructions = convert_instructions(roverdata.m_instructions);
            for(auto const& i : instructions)
            {
                roverdata.m_placement = i->act(roverdata.m_placement);
            }
        }
        
        std::stringstream outputstream;
        for (auto& roverdata : parsed_data.m_all_rover_data)
        {
            outputstream << roverdata.m_placement.m_x;
            outputstream << " ";
            outputstream << roverdata.m_placement.m_y;
            outputstream << " ";
            outputstream << orientation_to_string(roverdata.m_placement.m_orientation);
            outputstream << "\n";
        }
        auto str = outputstream.str();
        str.pop_back();
        
        return str;
        
        return 
R"foo(1 3 N
5 1 E)foo";
    }
    
    return "";
}


