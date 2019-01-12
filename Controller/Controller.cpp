//
// Created by Rabia on 29/12/2018.
//

#include <iostream>
#include <vector>
#include <exception>

#include "../Command/Command.h"
#include "Controller.h"


const std::string Controller::EXIT = "quit";
const std::string Controller::HELP = "help";


Controller::Controller(const std::shared_ptr<Remote> remote,
                       const std::shared_ptr<UI> ui,
                       const std::shared_ptr<CommandParser> parser)
{
    m_remote = remote;
    m_ui = ui;
    m_parser = parser;
    m_container = std::shared_ptr<DnaContainer>(new DnaContainer);

}


Controller::~Controller() {}


void Controller::start()
{
    // TODO: Split code into smaller responisbilities
    std::string line;
    std::string response;
    std::string commandName;
    do
    {

        line = m_ui->prompt();

        if ( line.find(EXIT) != -1 )
            break;

        std::vector<std::string> parsed = m_parser->parse(line);
        commandName = parsed[0];
        parsed.erase(parsed.begin());

        if ( commandName == HELP )
        {
            if ( parsed.size() == 0 )
                m_ui->render(m_remote->getHelp());
            else
                m_ui->render(m_remote->getHelp(parsed[0]));
            continue;
        }

        try
        {

            std::unique_ptr<Command> responseCmd =
                    m_remote->request(commandName, parsed);

            responseCmd->execute(m_container);

            response = responseCmd->getResponse();

            m_ui->render(response);
        }
        catch ( const std::exception &e )
        {
            response = e.what();

            m_ui->renderError(response);
        }

    } while ( true );

    return;
}

