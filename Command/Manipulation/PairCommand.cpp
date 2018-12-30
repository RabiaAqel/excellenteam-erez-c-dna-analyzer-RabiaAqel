//
// Created by Rabia on 30/12/2018.
//

#include "PairCommand.h"


const std::string PairCommand::COMMAND_NAME = "pair";


PairCommand::PairCommand (std::vector <std::string> args)
        : command_alias (COMMAND_NAME), m_args (args)
{}


PairCommand::~PairCommand ()
{}


std::string PairCommand::execute (std::shared_ptr<DnaContainer> container)
{
    return "Pairing....";
}


