//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_CREATIONCOMMAND_H
#define DNA_ANALYZER_CREATIONCOMMAND_H

#include "../Command.h"

class CreationCommand : public Command
{
public:

    CreationCommand () {};
    CreationCommand (std::string args) {};

    virtual ~CreationCommand () {};

    virtual void execute (std::shared_ptr<DnaContainer> container) = 0;

    virtual const std::string &getResponse () const = 0;

private:
    static const int MAX_ARGS;
    static const int MIN_ARGS;
    std::string m_response;
};


#endif //DNA_ANALYZER_CREATIONCOMMAND_H
