//
// Created by Rabia on 31/12/2018.
//

#include <sstream>

#include "New.h"


const std::string New::COMMAND_ALIAS = "new";
const std::string New::HELP = "usage: new <sequence> [@<sequence_name>]";


New::New(std::vector<std::string> args)
        : m_args(args)
{
    size_t args_count = m_args.size();

    if ( args_count > MAX_ARGS )
        throw TooManyArguments(COMMAND_ALIAS);
    if ( args_count < MIN_ARGS )
        throw TooFewArguments(COMMAND_ALIAS);


    if ( args_count == MAX_ARGS )
    {

        if ( m_args[1][0] != '@' )
            throw InvalidArgument(m_args[1]);
    }
}


New::~New() {}


void New::execute(std::shared_ptr<DnaContainer> container)
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


const std::string &New::getResponse() const
{
    return m_response;
}
