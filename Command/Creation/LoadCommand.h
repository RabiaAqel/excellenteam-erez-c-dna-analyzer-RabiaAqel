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

    LoadCommand(std::vector<std::string> args);

    ~LoadCommand();

    void execute(std::shared_ptr<DnaContainer> container);

    const std::string &getResponse() const;

    static const std::string &getAlias();

    static const std::string &help();

private:

    std::vector<std::string> m_args;
    static const int MAX_ARGS = 2;
    static const int MIN_ARGS = 1;
    std::string m_response;
    static const std::string COMMAND_ALIAS;
    static const std::string HELP;
};


inline const std::string &LoadCommand::getAlias()
{
    return COMMAND_ALIAS;
}


inline const std::string &LoadCommand::help()
{
    return HELP;
}


#endif //DNA_ANALYZER_LOADCOMMAND_H
