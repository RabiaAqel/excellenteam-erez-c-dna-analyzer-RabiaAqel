//
// Created by Rabia on 30/12/2018.
//


#include <iostream>

#include "ListCommand.h"


const std::string ListCommand::COMMAND_NAME = "list";


ListCommand::ListCommand (std::vector<std::string> args)
        : command_alias (COMMAND_NAME), m_args (args)
{}


ListCommand::~ListCommand ()
{}


std::string ListCommand::execute (std::shared_ptr<DnaContainer> container)
{
    std::string list = container->getList ();

    return (list == "") ? "DNA Analyzer: No active sequences" : list;

}


