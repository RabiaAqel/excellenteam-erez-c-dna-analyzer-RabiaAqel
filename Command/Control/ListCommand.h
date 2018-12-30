//
// Created by Rabia on 30/12/2018.
//

#ifndef DNA_ANALYZER_LISTCOMMAND_H
#define DNA_ANALYZER_LISTCOMMAND_H

#include <vector>
#include <string>

#include "ControlCommand.h"

class ListCommand : public ControlCommand
{
public:

    ListCommand (std::vector<std::string> args);
    ~ListCommand ();

    std::string execute (std::shared_ptr<DnaContainer> container);

private:

    std::vector<std::string> m_args;
    static const std::string COMMAND_NAME;
    static const std::string ARGS_FORMAT;
    mutable std::string command_alias;
};


#endif //DNA_ANALYZER_LISTCOMMAND_H
