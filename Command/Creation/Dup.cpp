//
// Created by Rabia on 12/01/2019.
//

#include "Dup.h"

//
// Created by Rabia on 31/12/2018.
//


const std::string Dup::COMMAND_ALIAS = "dup";
const std::string Dup::HELP = "usage: dup <seq> [@<new_seq_name>]";


Dup::Dup(std::vector<std::string> args)
        : m_args(args)
{
// TODO
}


Dup::~Dup() {}


void Dup::execute(std::shared_ptr<DnaContainer> container)
{
    m_response = "Command Not supported yet!";
}


const std::string &Dup::getResponse() const
{
    return m_response;
}
