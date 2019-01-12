//
// Created by Rabia on 31/12/2018.
//

#ifndef DNA_ANALYZER_New_H
#define DNA_ANALYZER_New_H

#include "../Command.h"


class New : public Command
{

public:

    New(std::vector<std::string> args);

    ~New();

    void execute(std::shared_ptr<DnaContainer> container);

    const std::string &getResponse() const;

    static const std::string &getAlias();

    static const std::string &help();

private:

    std::vector<std::string> m_args;
    static const int MAX_ARGS = 2;
    static const int MIN_ARGS = 1;
    std::string m_response;
    static const std::string COMMAND_ALIAS;
    static const std::string HELP;
};


inline const std::string &New::getAlias()
{
    return COMMAND_ALIAS;
}


inline const std::string &New::help()
{
    return HELP;
}

#endif //DNA_ANALYZER_New_H
