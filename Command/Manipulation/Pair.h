//
// Created by Rabia on 30/12/2018.
//

#ifndef DNA_ANALYZER_PAIR_H
#define DNA_ANALYZER_PAIR_H

#include <string>
#include <vector>

#include "../Command.h"

class Pair : public Command
{
public:

    enum E_FLAG
    {
        NONE = 0,
        REPLACE = 1,
        CREATE_NEW = 2
    };

    Pair(std::vector<std::string> args);

    ~Pair();

    void execute(std::shared_ptr<DnaContainer> container);

    const std::string &getResponse() const;

    static const std::string &getAlias();

    static const std::string &help();

private:

    std::vector<std::string> m_args;
    static const std::string COMMAND_ALIAS;
    static const std::string HELP;
    static const std::string ARGS_FORMAT;
    static const int MAX_ARGS = 3;
    static const int MIN_ARGS = 1;
    E_FLAG m_flag;
    std::string m_response;
};


inline const std::string &Pair::getAlias()
{
    return COMMAND_ALIAS;
}


inline const std::string &Pair::help()
{
    return HELP;
}


#endif //DNA_ANALYZER_PAIR_H
