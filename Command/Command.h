//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_COMMAND_H
#define DNA_ANALYZER_COMMAND_H

#include <string>
#include <vector>

#include "../Model/DnaContainer.h"
#include "../Exceptions/TooFewArgumentException.h"
#include "../Exceptions/TooManyArgumentsException.h"
#include "../Exceptions/InvalidArgumentException.h"


class Command
{
public:

    Command () {};

    Command (std::vector<std::string> args) : m_args (args) {};

    virtual ~Command () {};

    virtual void execute (std::shared_ptr<DnaContainer> container) = 0;

    virtual void setAlias (const std::string &alias) const;

    virtual std::string getAlias ();

    virtual const std::string &getResponse () const = 0;

private:
    std::vector<std::string> m_args;
    static const int MAX_ARGS;
    static const int MIN_ARGS;
    static const std::string COMMAND_NAME;
    mutable std::string command_alias;
    std::string m_response;
};


inline void Command::setAlias (const std::string &alias) const
{
    command_alias = alias;
}


inline std::string Command::getAlias ()
{
    return command_alias;
}


#endif //DNA_ANALYZER_COMMAND_H
