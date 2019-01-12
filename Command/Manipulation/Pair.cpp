//
// Created by Rabia on 30/12/2018.
//

#include <sstream>

#include "Pair.h"
#include "../Creation/New.h"


const std::string Pair::COMMAND_ALIAS = "pair";
const std::string Pair::HELP = "usage: pair <seq> [: [@<new_seq_name>|@@]]";


Pair::Pair(std::vector<std::string> args)
        : m_args(args), m_flag(NONE)
{
    size_t args_count = m_args.size();

    if ( args_count > MAX_ARGS )
        throw TooManyArguments(COMMAND_ALIAS);
    if ( args_count < MIN_ARGS )
        throw TooFewArguments(COMMAND_ALIAS);


    if ( m_args[0][0] != '#' && m_args[0][0] != '@' )
        throw InvalidArgument("seqname");


    if ( args_count == MAX_ARGS )
    {
        m_flag = CREATE_NEW;

        if ( m_args[1][0] != ':' )
            throw InvalidArgument("no :");

        if ( m_args[2] != "@@" && m_args[2][0] != '@' )
            throw InvalidArgument("name generation err");
    }
    else
    {
        m_flag = REPLACE;
    }


}


Pair::~Pair() {}


void Pair::execute(std::shared_ptr<DnaContainer> container)
{
    std::stringstream ss;


    if ( m_args[0][0] == '@' )
    {
        std::string sequenceName = m_args[0].erase(0, 1);

        container->pair(sequenceName);

        ss << *container->findByName(sequenceName);
    }
    else
    {
        size_t id = (size_t) std::stoi(m_args[0].erase(0, 1));

        container->pair(id);

        ss << *container->findByID(id);
    }

    m_response = ss.str();
}


const std::string &Pair::getResponse() const
{
    return m_response;
}

