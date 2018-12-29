//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_CREATIONCOMMAND_H
#define DNA_ANALYZER_CREATIONCOMMAND_H

#include "Command.h"

class CreationCommand : public Command
{
public:

    CreationCommand () {};
    CreationCommand (std::string args) {};

    virtual ~CreationCommand () {};

    virtual std::string execute () = 0;
};


#endif //DNA_ANALYZER_CREATIONCOMMAND_H
