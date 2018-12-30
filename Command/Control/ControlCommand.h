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

    ControlCommand () {};
    virtual ~ControlCommand () {};

    virtual std::string execute (std::shared_ptr<DnaContainer> container) = 0;

};


#endif //DNA_ANALYZER_CONTROLCOMMAND_H