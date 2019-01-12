//
// Created by Rabia on 28/12/2018.
//

#include <iostream>

#include "CommandRemote.h"
#include "../Exceptions/InvalidCommand.h"
#include "../Command/Management/SaveCommand.h"
#include "../Command/Creation/LoadCommand.h"
#include "../Command/Control/ListCommand.h"
#include "../Command/Manipulation/PairCommand.h"
#include "../Command/Creation/NewCommand.h"

#include <vector>


template<typename T>
std::unique_ptr<T> creator(std::vector<std::string> args)
{
    return std::unique_ptr<T>(new T(args));
}


CommandRemote::CommandRemote()
{
    boot();
}


CommandRemote::~CommandRemote() {}


void CommandRemote::boot()
{
    m_buttons[SaveCommand::getAlias()] = (CreatorFunction) creator<SaveCommand>;
    m_buttons[LoadCommand::getAlias()] = (CreatorFunction) creator<LoadCommand>;
    m_buttons[PairCommand::getAlias()] = (CreatorFunction) creator<PairCommand>;
    m_buttons[NewCommand::getAlias()] = (CreatorFunction) creator<NewCommand>;
    m_buttons[ListCommand::getAlias()] = (CreatorFunction) creator<ListCommand>;
}


std::unique_ptr<Command> CommandRemote::request(const std::string &COMMAND_ALIAS,
                                                std::vector<std::string> args)
{
    if ( m_buttons.find(COMMAND_ALIAS) != m_buttons.end())
        return m_buttons.find(COMMAND_ALIAS)->second(args);
    else
        throw DnaAnalyzerExceptions::InvalidCommand(COMMAND_ALIAS);
}


std::string CommandRemote::getHelp() const
{
    return ("DNA Analyzer Commands: \n\n\t"
            + NewCommand::help() + "\n\t"
            + LoadCommand::help() + "\n\t"
            + PairCommand::help() + "\n\t"
            + SaveCommand::help() + "\n\t"
            + ListCommand::help() + "\n\t"
    );
}


