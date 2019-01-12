//
// Created by Rabia on 28/12/2018.
//

#ifndef DNA_ANALYZER_COMMANDCONTROLLER_H
#define DNA_ANALYZER_COMMANDCONTROLLER_H

#include <map>
#include "Remote.h"


class CommandRemote : public Remote
{
public:

    CommandRemote();

    ~CommandRemote();

    std::unique_ptr<Command> request(const std::string &command,
                                     std::vector<std::string> args);

    void boot();

    std::string getHelp() const;

private:
    std::map<std::string, CreatorFunction> m_buttons;
};


#endif //DNA_ANALYZER_COMMANDCONTROLLER_H
