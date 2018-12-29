//
// Created by Rabia on 28/12/2018.
//

#ifndef DNA_ANALYZER_COMMANDCONTROLLER_H
#define DNA_ANALYZER_COMMANDCONTROLLER_H

#include "Remote.h"


class CommandRemote : public Remote
{
public:
    CommandRemote ();

    ~CommandRemote ();

    void boot ();


    std::unique_ptr<Command> request (const std::string &command,
                                      std::vector<std::string> args);
//    std::unique_ptr <Command> func (const std::string &command_name, const std::string &args);
};


#endif //DNA_ANALYZER_COMMANDCONTROLLER_H
