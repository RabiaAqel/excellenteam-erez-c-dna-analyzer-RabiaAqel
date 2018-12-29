//
// Created by Rabia on 27/12/2018.
//

#ifndef DNA_ANALYZER_REMOTE_H
#define DNA_ANALYZER_REMOTE_H


#include <string>
#include <vector>

#include "Command/Command.h"


class Remote
{
public:
    Remote () {} ;
    virtual ~Remote () {};

    virtual void boot () = 0;

    virtual std::unique_ptr<Command> request (const std::string &command,
            std::vector<std::string> args) = 0;

//privat
// e:
//    std::map<std::string, std::unique_ptr<Command> > Commands;
};


#endif //DNA_ANALYZER_REMOTE_H
