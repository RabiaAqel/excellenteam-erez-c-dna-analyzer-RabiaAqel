//
// Created by Rabia on 30/12/2018.
//

#include "PairCommand.h"


const std::string PairCommand::COMMAND_NAME = "pair";


PairCommand::PairCommand (std::vector<std::string> args)
        : command_alias (COMMAND_NAME), m_args (args)
{
    size_t args_count = m_args.size ();

    if ( args_count > MAX_ARGS )
        throw TooManyArgumentsException ();
    if ( args_count < MIN_ARGS )
        throw TooFewArgumentsException ();
}


PairCommand::~PairCommand () {}


void PairCommand::execute (std::shared_ptr<DnaContainer> container)
{
    m_response =;
}


const std::string &PairCommand::getResponse () const
{
    return m_response;
}

