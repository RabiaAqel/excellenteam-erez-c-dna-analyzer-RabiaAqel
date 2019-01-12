//
// Created by Rabia on 27/12/2018.
//

#ifndef DNA_ANALYZER_REMOTE_H
#define DNA_ANALYZER_REMOTE_H


#include <string>
#include <vector>

#include "../Command/Command.h"

typedef std::unique_ptr<Command> (*CreatorFunction)(std::vector<std::string> args);

class Remote
{
public:

    Remote() {};

    virtual ~Remote() {};

    virtual void boot() = 0;

    virtual std::unique_ptr<Command> request(const std::string &command,
                                             std::vector<std::string> args) = 0;

    virtual std::string getHelp() const = 0;

private:
    static std::map<std::string, CreatorFunction> m_buttons;
};


#endif //DNA_ANALYZER_REMOTE_H
