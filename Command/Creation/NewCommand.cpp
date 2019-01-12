//
// Created by Rabia on 31/12/2018.
//

#include <sstream>

#include "NewCommand.h"


const std::string NewCommand::COMMAND_ALIAS = "new";
const std::string NewCommand::HELP = "usage: new <sequence> [@<sequence_name>]";


NewCommand::NewCommand(std::vector<std::string> args)
        : m_args(args)
{
    size_t args_count = m_args.size();

    if ( args_count > MAX_ARGS )
        throw DnaAnalyzerExceptions::TooManyArguments(COMMAND_ALIAS);
    if ( args_count < MIN_ARGS )
        throw DnaAnalyzerExceptions::TooFewArguments(COMMAND_ALIAS);


    if ( args_count == MAX_ARGS )
    {

        if ( m_args[1][0] != '@' )
            throw DnaAnalyzerExceptions::InvalidArgument(m_args[1]);
    }
}


NewCommand::~NewCommand() {}


void NewCommand::execute(std::shared_ptr<DnaContainer> container)
{
    size_t id = 0;
    std::stringstream ss;

    if ( m_args.size() == MAX_ARGS )
    {
        std::string sequenceName = m_args[1];
        id = container->insert(sequenceName.erase(0, 1), m_args[0], 'o');
    }
    else
    {
        id = container->insert(m_args[0], 'o');
    }

    ss << *container->findByID(id);

    m_response = ss.str();
}


const std::string &NewCommand::getResponse() const
{
    return m_response;
}
