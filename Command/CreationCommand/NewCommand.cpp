//
// Created by Rabia on 31/12/2018.
//

#include "NewCommand.h"

const std::string NewCommand::COMMAND_NAME = "new";


NewCommand::NewCommand (std::vector<std::string> args)
        : command_alias (COMMAND_NAME), m_args (args)
{
    size_t args_count = m_args.size ();

    if ( args_count > MAX_ARGS )
        throw TooManyArgumentsException ();
    if ( args_count < MIN_ARGS )
        throw TooFewArgumentsException ();


    if ( args_count == MAX_ARGS )
    {
        if ( m_args[1][0] != '@' )
            throw InvalidArgumentException ();
    }
}


NewCommand::~NewCommand () {}


void NewCommand::execute (std::shared_ptr<DnaContainer> container)
{
    if ( m_args.size () == MAX_ARGS )
    {
        std::string sequenceName = m_args[1];
        container->insert (sequenceName.erase (0, 1), m_args[0]);
    }
    else
    {
        container->insert (m_args[0]);
    }

    m_response = "success";
}


const std::string &NewCommand::getResponse () const
{
    return m_response;
}