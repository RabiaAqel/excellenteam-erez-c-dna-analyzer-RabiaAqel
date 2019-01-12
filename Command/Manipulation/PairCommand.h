//
// Created by Rabia on 30/12/2018.
//

#ifndef DNA_ANALYZER_PAIRCOMMAND_H
#define DNA_ANALYZER_PAIRCOMMAND_H

#include <string>
#include <vector>

#include "ManipulationCommand.h"

class PairCommand : public ManipulationCommand
{
public:

    PairCommand(std::vector<std::string> args);

    ~PairCommand();

    void execute(std::shared_ptr<DnaContainer> container);

    const std::string &getResponse() const;

    static const std::string &getAlias();

    static const std::string &help();

private:

    std::vector<std::string> m_args;
    static const std::string COMMAND_ALIAS;
    static const std::string HELP;
    static const std::string ARGS_FORMAT;
    static const int MAX_ARGS = 2;
    static const int MIN_ARGS = 1;
    std::string m_response;
};


inline const std::string &PairCommand::getAlias()
{
    return COMMAND_ALIAS;
}


inline const std::string &PairCommand::help()
{
    return HELP;
}


#endif //DNA_ANALYZER_PAIRCOMMAND_H
