//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_MANIPULATIONCOMMAND_H
#define DNA_ANALYZER_MANIPULATIONCOMMAND_H

#include "../Command.h"

class ManipulationCommand : public Command
{
public:

    ManipulationCommand() {};
    ManipulationCommand(std::vector<std::string> args) {};
    virtual ~ManipulationCommand () {};

    virtual std::string execute (std::shared_ptr<DnaContainer> container) = 0;

};


#endif //DNA_ANALYZER_MANIPULATIONCOMMAND_H
