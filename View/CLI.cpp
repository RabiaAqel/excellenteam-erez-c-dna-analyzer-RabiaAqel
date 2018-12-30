//
// Created by Rabia on 25/12/2018.
//

#include "CLI.h"


const char CLI::EXIT_MESSAGE[] = "Goodbye.\n";
const char CLI::EXIT_COMMAND[] = "exit";
const char CLI::PROMPT[] = "\033[0;36mDNA Analyzer >>> \033[0m";


CLI::CLI () {}


CLI::~CLI () {}


void CLI::render (std::string out)
{
    std::cout << out << std::endl;
    return;
}


void CLI::renderError (std::string error)
{
    std::cerr << error << std::endl;
    return;
}


std::string CLI::prompt ()
{
    std::string line;
    std::cout << PROMPT;
    std::getline (std::cin, line);
    return line;
}
