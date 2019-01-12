//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_MANAGEMENTCOMMAND_H
#define DNA_ANALYZER_MANAGEMENTCOMMAND_H

#include "../Command.h"

class ManagementCommand : public Command
{
public:

    ManagementCommand() {};

    ManagementCommand(std::vector<std::string> args) {};

    virtual ~ManagementCommand() {};

    virtual void execute(std::shared_ptr<DnaContainer> container) = 0;

    virtual const std::string &getResponse() const = 0;


private:
    static const std::string COMMAND_ALIAS;

};


#endif //DNA_ANALYZER_MANAGEMENTCOMMAND_H
