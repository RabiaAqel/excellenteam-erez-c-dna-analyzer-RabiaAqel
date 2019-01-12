//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_CONTROLCOMMAND_H
#define DNA_ANALYZER_CONTROLCOMMAND_H

#include <string>

#include "../Command.h"


class ControlCommand : public Command
{
public:

    ControlCommand() {};

    virtual ~ControlCommand() {};

    virtual void execute(std::shared_ptr<DnaContainer> container) = 0;

    virtual const std::string &getResponse() const = 0;

    static const std::string &getAlias();


private:
    static const std::string COMMAND_ALIAS;

};


#endif //DNA_ANALYZER_CONTROLCOMMAND_H
