#ifndef CONVERT_INSTRUCTIONS_HPP
#define CONVERT_INSTRUCTIONS_HPP

#include <string>
#include <vector>
#include <memory>
#include "instruction_interface.hpp"

std::vector<std::shared_ptr<InstructionInterface>> convert_instructions(std::string const& input);

#endif