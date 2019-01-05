//
// Created by Rabia on 29/12/2018.
//

#include <iostream>
#include <vector>
#include <exception>

#include "../Command/Command.h"
#include "Controller.h"


Controller::Controller (const std::shared_ptr<Remote> remote,
                        const std::shared_ptr<UI> ui,
                        const std::shared_ptr<CommandParser> parser)
{
    m_remote = remote;
    m_ui = ui;
    m_parser = parser;
    m_container = std::shared_ptr<DnaContainer> (new DnaContainer);

}


Controller::~Controller () {}


void Controller::start ()
{
    // TODO: Split code into smaller responisbilities
    std::string line;
    std::string response;
    std::string commandName;
    do
    {

        line = m_ui->prompt ();

        std::vector<std::string> parsed = m_parser->parse (line);


        if ( !line.empty ())
        {

            if ( line.find ("exit") != -1 )
                break;
            else
            {

                try
                {

                    commandName = parsed.front ();

                    parsed.erase (parsed.begin ());

                    std::unique_ptr<Command> responseCmd =
                            m_remote->request (commandName, parsed);

                    responseCmd->execute (m_container);
                    response = responseCmd->getResponse ();


                    m_ui->render (response);
                }
                catch ( std::exception &e )
                {
                    response = e.what ();
                    m_ui->renderError (response);
                }
            }
        }
    } while ( true );
    return;
}


void Controller::help ()
{

}
