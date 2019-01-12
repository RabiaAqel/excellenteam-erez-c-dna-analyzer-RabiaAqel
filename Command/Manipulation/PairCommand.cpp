//
// Created by Rabia on 30/12/2018.
//

#include "PairCommand.h"


const std::string PairCommand::COMMAND_ALIAS = "pair";
const std::string PairCommand::HELP = "usage: pair <seq> [: [@<new_seq_name>|@@]]";


PairCommand::PairCommand(std::vector<std::string> args)
        : m_args(args)
{
    size_t args_count = m_args.size();

    if ( args_count > MAX_ARGS )
        throw DnaAnalyzerExceptions::TooManyArguments(COMMAND_ALIAS);
    if ( args_count < MIN_ARGS )
        throw DnaAnalyzerExceptions::TooFewArguments(COMMAND_ALIAS);
}


PairCommand::~PairCommand() {}


void PairCommand::execute(std::shared_ptr<DnaContainer> container)
{
    m_response = "weeeeeeee.......";
}


const std::string &PairCommand::getResponse() const
{
    return m_response;
}

