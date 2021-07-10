#include "mars_rover.hpp"
#include <gtest/gtest.h>
#include <utility>
#include <sstream>
#include "input_parser.hpp"

using namespace ::testing;

class ParserTestFixture : public testing::TestWithParam<std::pair<std::string, bool>>
{
};

INSTANTIATE_TEST_CASE_P(
        ParserTest,
        ParserTestFixture,
        ::testing::Values(
            std::make_pair(std::string(""), false),
            std::make_pair(std::string(R"foo(5 5
1 2 N
L)foo"), true),
            std::make_pair(std::string(" "), false),
            std::make_pair(std::string("a b"), false),
            std::make_pair(std::string("5 "), false)
            )
    );
    
TEST_P(ParserTestFixture, input_parse_succeeds)
{
    auto const input = GetParam().first;
    auto expected_result = GetParam().second;
    
    RemoteCommandData parsed_data;
    bool parse_succeeded = parse(input, parsed_data);

    EXPECT_EQ(expected_result, parse_succeeded);
}

TEST(Parser, input_parses_grid_dimension)
{
    auto const input = 
    "5 6";
    RemoteCommandData parsed_data;
    bool parse_succeeded = parse(input, parsed_data);

    EXPECT_TRUE(parse_succeeded);
    EXPECT_EQ(parsed_data.m_plateau_size.m_width, 5);
    EXPECT_EQ(parsed_data.m_plateau_size.m_height, 6);
}


TEST(Parser, first_rover_position_should_be_parsed_correctly)
{
    auto const input = 
R"foo(5 5
1 2 N)foo";
    RemoteCommandData parsed_data;
    auto const expected_placement = RoverPlacement{ 1, 2, NORTH };
    parse(input, parsed_data);

    EXPECT_EQ(expected_placement, parsed_data.m_all_rover_data.at(0).m_placement);
}

TEST(Parser, first_rover_position_should_be_parsed_correctly_really)
{
    auto const input = 
R"foo(6 9
4 1 E)foo";
    RemoteCommandData parsed_data;
    auto const expected_placement = RoverPlacement{ 4, 1, EAST };
    parse(input, parsed_data);

    EXPECT_EQ(expected_placement, parsed_data.m_all_rover_data.at(0).m_placement);
}

TEST(Parser, first_rover_instructions_should_be_parsed_correctly)
{
    auto const input = 
R"foo(6 9
4 1 E
LMLMLMLMM)foo";
    RemoteCommandData parsed_data;
    auto const expected_instructions = std::string("LMLMLMLMM");
    parse(input, parsed_data);

    EXPECT_EQ(expected_instructions, parsed_data.m_all_rover_data.at(0).m_instructions);
}


TEST(Parser, east_orientation_conversion_works_correctly)
{
    std::string const input = "E";
    roverOrientation expected_orientation = EAST;
    
    EXPECT_EQ(expected_orientation, convert_orientation(input));
}

TEST(Parser, west_orientation_conversion_works_correctly)
{
    std::string const input = "W";
    roverOrientation expected_orientation = WEST;
    
    EXPECT_EQ(expected_orientation, convert_orientation(input));
}

TEST(Parser, north_orientation_conversion_works_correctly)
{
    std::string const input = "N";
    roverOrientation expected_orientation = NORTH;
    
    EXPECT_EQ(expected_orientation, convert_orientation(input));
}

TEST(Parser, south_orientation_conversion_works_correctly)
{
    std::string const input = "S";
    roverOrientation expected_orientation = SOUTH;
    
    EXPECT_EQ(expected_orientation, convert_orientation(input));
}


TEST(Parser, two_rovers_complete_rover_data)
{
    auto const input = 
R"foo(6 9
4 1 E
LMLMLMLMM
3 4 W
MMLMMMRMM)foo";
    
    auto const expected_placement_rover_1 = RoverPlacement{ 4, 1, EAST };
    auto const expected_placement_rover_2 = RoverPlacement{ 3, 4, WEST };
    auto const expected_instructions_rover_1 = std::string("LMLMLMLMM");
    auto const expected_instructions_rover_2 = std::string("MMLMMMRMM");

    RoverData rover1{expected_placement_rover_1, expected_instructions_rover_1};
    
    RoverData rover2{expected_placement_rover_2, expected_instructions_rover_2};
    
    RemoteCommandData parsed_data;
    parse(input, parsed_data);
    EXPECT_EQ(parsed_data.m_all_rover_data.at(0), rover1);
    EXPECT_EQ(parsed_data.m_all_rover_data.at(1), rover2);
}
