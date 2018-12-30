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

    PairCommand (std::vector<std::string> args);
    ~PairCommand ();

    std::string execute (std::shared_ptr<DnaContainer> container);

private:

    std::vector<std::string> m_args;
    static const std::string COMMAND_NAME;
    static const std::string ARGS_FORMAT;
    mutable std::string command_alias;
};


#endif //DNA_ANALYZER_PAIRCOMMAND_H
