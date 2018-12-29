//
// Created by Rabia on 23/12/2018.
//

#ifndef DNA_ANALYZER_COMMAND_H
#define DNA_ANALYZER_COMMAND_H

#include <string>
#include <vector>


class Command
{
public:

    Command() {};
    Command (std::vector<std::string> args) : m_args(args) {};
    virtual ~Command () {};

    virtual std::string execute () = 0;

    virtual void setAlias (const std::string& alias) const;
    virtual std::string getAlias ();

private:
    std::vector<std::string> m_args;
    static const std::string ARGS_FORMAT;
    static const std::string COMMAND_NAME;
    mutable std::string command_alias;
};

inline void Command::setAlias (const std::string& alias) const
{
    command_alias = alias;
}


inline std::string Command::getAlias ()
{
    return command_alias;
}


#endif //DNA_ANALYZER_COMMAND_H
