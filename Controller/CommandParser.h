//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_COMMANDPARSER_H
#define DNA_ANALYZER_COMMANDPARSER_H

#include <string>

class CommandParser
{
public:

    CommandParser ();
    ~CommandParser ();

    std::vector<std::string> parse (const std::string &input);
};


#endif //DNA_ANALYZER_COMMANDPARSER_H
