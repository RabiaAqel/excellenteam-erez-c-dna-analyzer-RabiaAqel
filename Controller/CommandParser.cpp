//
// Created by Rabia on 29/12/2018.
//

#include "CommandParser.h"
#include <boost/algorithm/string.hpp>


const std::string CommandParser::SEPARATOR = " ";


CommandParser::CommandParser() {}

CommandParser::~CommandParser() {}


std::vector<std::string> CommandParser::parse(const std::string &input)
{
    std::vector<std::string> result;
    boost::split(result, input, boost::is_any_of(SEPARATOR));
    return result;
}

