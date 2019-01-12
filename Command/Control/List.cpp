//
// Created by Rabia on 30/12/2018.
//


#include <iostream>

#include "List.h"


const std::string List::COMMAND_ALIAS = "list";
const std::string List::HELP = "usage: list";


List::List(std::vector<std::string> args)
        : m_args(args) {}


List::~List() {}


void List::execute(std::shared_ptr<DnaContainer> container)
{
    std::string list = container->getList();

    m_response = (list == "") ? "DNA Analyzer: No active sequences" : list;
}


const std::string &List::getResponse() const
{
    return m_response;
}


