//
// Created by Rabia on 29/12/2018.
//

#ifndef DNA_ANALYZER_CONTROLLER_H
#define DNA_ANALYZER_CONTROLLER_H

#include "Remote.h"
#include "UI.h"
#include "CommandParser.h"


class Controller
{
public:
    Controller(const std::shared_ptr<Remote> remote,
            const std::shared_ptr<UI> ui,
            const std::shared_ptr<CommandParser> parser);
    ~Controller ();

    void start();


private:
    std::shared_ptr<Remote> m_remote;
    std::shared_ptr<UI> m_ui;
    std::shared_ptr<CommandParser> m_parser;
};


#endif //DNA_ANALYZER_CONTROLLER_H
