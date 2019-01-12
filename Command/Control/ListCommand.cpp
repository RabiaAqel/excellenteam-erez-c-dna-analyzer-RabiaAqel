//
// Created by Rabia on 30/12/2018.
//


#include <iostream>

#include "ListCommand.h"


const std::string ListCommand::COMMAND_ALIAS = "list";
const std::string ListCommand::HELP = "usage: list";


ListCommand::ListCommand(std::vector<std::string> args)
        : m_args(args) {}


ListCommand::~ListCommand() {}


void ListCommand::execute(std::shared_ptr<DnaContainer> container)
{
    std::string list = container->getList();

    m_response = (list == "") ? "DNA Analyzer: No active sequences" : list;
}


const std::string &ListCommand::getResponse() const
{
    return m_response;
}


