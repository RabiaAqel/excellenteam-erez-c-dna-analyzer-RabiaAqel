//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_MANAGEMENTCOMMAND_H
#define DNA_ANALYZER_MANAGEMENTCOMMAND_H

#include "Command.h"

class ManagementCommand : public Command
{
public:

    ManagementCommand () {};
    ManagementCommand (std::vector<std::string> args)
    {};
    virtual ~ManagementCommand ()
    {};

    virtual std::string execute () = 0;
};


#endif //DNA_ANALYZER_MANAGEMENTCOMMAND_H
