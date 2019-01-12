//
// Created by Rabia on 30/12/2018.
//

#ifndef DNA_ANALYZER_List_H
#define DNA_ANALYZER_List_H

#include <vector>
#include <string>

#include "../Command.h"

class List : public Command
{
public:

    List(std::vector<std::string> args);

    ~List();

    void execute(std::shared_ptr<DnaContainer> container);

    const std::string &getResponse() const;

    static const std::string &getAlias();

    static const std::string &help();

private:

    std::vector<std::string> m_args;
    static const std::string COMMAND_ALIAS;
    static const std::string ARGS_FORMAT;
    static const std::string HELP;
    std::string m_response;

};


inline const std::string &List::getAlias()
{
    return COMMAND_ALIAS;
}


inline const std::string &List::help()
{
    return HELP;
}


#endif //DNA_ANALYZER_List_H
