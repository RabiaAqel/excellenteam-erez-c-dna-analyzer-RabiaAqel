//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_CONTROLCOMMAND_H
#define DNA_ANALYZER_CONTROLCOMMAND_H


#include "Command.h"

class ControlCommand : public Command
{
public:

    virtual ControlCommand () = 0;
    virtual ~ControlCommand () = 0;

    virtual execute () = 0;

};


#endif //DNA_ANALYZER_CONTROLCOMMAND_H
