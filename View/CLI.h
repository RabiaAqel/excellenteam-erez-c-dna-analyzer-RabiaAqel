//
// Created by Rabia on 25/12/2018.
//

#ifndef DNA_ANALYZER_CLI_H
#define DNA_ANALYZER_CLI_H

#include <string>
#include <iostream>

#include "UI.h"

class CLI : public UI
{
public:

    CLI();

    ~CLI();

    void render(std::string out);

    void renderError(std::string error);

    std::string prompt();

private:

    static const char PROMPT[];
};


#endif //DNA_ANALYZER_CLI_H
