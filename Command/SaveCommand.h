//
// Created by Rabia on 27/12/2018.
//

#ifndef DNA_ANALYZER_SAVECOMMAND_H
#define DNA_ANALYZER_SAVECOMMAND_H

#include <iostream>

#include "ManagementCommand.h"

class SaveCommand : public ManagementCommand
{
public:

    SaveCommand (std::vector<std::string> args);
    ~SaveCommand ();

    std::string execute ();

private:
    std::vector<std::string> m_args;
    static const std::string COMMAND_NAME;
    mutable std::string command_alias;
};


#endif //DNA_ANALYZER_SAVECOMMAND_H
