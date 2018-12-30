//
// Created by Rabia on 27/12/2018.
//

#ifndef DNA_ANALYZER_LOADCOMMAND_H
#define DNA_ANALYZER_LOADCOMMAND_H

#include <iostream>
#include <vector>

#include "CreationCommand.h"


class LoadCommand : public CreationCommand
{
public:

    LoadCommand (std::vector<std::string> args);
    ~LoadCommand ();

    std::string execute (std::shared_ptr<DnaContainer> container);

private:

    std::vector<std::string> m_args;
    static const std::string COMMAND_NAME;
    static const std::string ARGS_FORMAT;
    mutable std::string command_alias;
};


#endif //DNA_ANALYZER_LOADCOMMAND_H
