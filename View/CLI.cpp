//
// Created by Rabia on 25/12/2018.
//

#include "CLI.h"

const char CLI::PROMPT[] = "\033[0;36mDNA Analyzer > \033[0m";


CLI::CLI() {}


CLI::~CLI() {}


void CLI::render(std::string out)
{
    std::cout << out << std::endl;
    return;
}


void CLI::renderError(std::string error)
{
    std::cerr << "\033[1;31m" << error << "\033[0m" << std::endl;
    return;
}


std::string CLI::prompt()
{
    std::string line;

    for ( line; std::cout << PROMPT && std::getline(std::cin, line) && line.empty(); );

    return line;
}
