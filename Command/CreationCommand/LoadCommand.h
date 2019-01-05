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

    void execute (std::shared_ptr<DnaContainer> container);

    const std::string &getResponse () const;

private:

    std::vector<std::string> m_args;
    static const std::string COMMAND_NAME;
    static const int MAX_ARGS = 2;
    static const int MIN_ARGS = 1;
    mutable std::string command_alias;
    std::string m_response;
};


#endif //DNA_ANALYZER_LOADCOMMAND_H
