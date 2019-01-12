//
// Created by Rabia on 27/12/2018.
//

#ifndef DNA_ANALYZER_Save_H
#define DNA_ANALYZER_Save_H

#include <iostream>

#include "../Command.h"

class Save : public Command
{
public:

    Save(std::vector<std::string> args);

    ~Save();

    void execute(std::shared_ptr<DnaContainer> container);

    const std::string generateName();

    const std::string &getResponse() const;

    static const std::string &getAlias();

    static const std::string &help();

private:
    std::vector<std::string> m_args;
    static const std::string COMMAND_ALIAS;
    static const std::string HELP;
    static const int MAX_ARGS = 2;
    static const int MIN_ARGS = 1;
    std::string m_response;

};


inline const std::string &Save::getAlias()
{
    return COMMAND_ALIAS;
}


inline const std::string &Save::help()
{
    return HELP;
}


#endif //DNA_ANALYZER_Save_H
