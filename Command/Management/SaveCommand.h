//
// Created by Rabia on 27/12/2018.
//

#ifndef DNA_ANALYZER_SAVECOMMAND_H
#define DNA_ANALYZER_SAVECOMMAND_H

#include <iostream>

#include "ManagementCommand.h"

class SaveCommand : public ManagementCommand
{
public:

    SaveCommand (std::vector<std::string> args);
    ~SaveCommand ();

    void execute (std::shared_ptr<DnaContainer> container);

    const std::string generateName ();

    const std::string &getResponse () const;

private:
    std::vector<std::string> m_args;
    static const std::string COMMAND_NAME;
    static const int MAX_ARGS = 2;
    static const int MIN_ARGS = 1;
    mutable std::string command_alias;
    std::string m_response;

};


#endif //DNA_ANALYZER_SAVECOMMAND_H
