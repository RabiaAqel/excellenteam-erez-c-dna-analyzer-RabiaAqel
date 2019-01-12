//
// Created by Rabia on 28/12/2018.
//

#include <iostream>

#include "CommandRemote.h"
#include "../Exceptions/InvalidCommand.h"
#include "../Command/Management/Save.h"
#include "../Command/Creation/Load.h"
#include "../Command/Control/List.h"
#include "../Command/Manipulation/Pair.h"
#include "../Command/Creation/New.h"
#include "../Command/Creation/Dup.h"

#include <vector>


const std::string CommandRemote::HELP_TITLE = "\"DNA Analyzer Commands: \\n\\n\\t\"";
const std::string CommandRemote::SEPARATOR = "\n\t";


template<typename T>
std::unique_ptr<T> creator(std::vector<std::string> args)
{
    return std::unique_ptr<T>(new T(args));
}

template<typename T>
ButtonConfig configure()
{
    return ButtonConfig((CreatorFunction) creator<T>, T::help());
}


CommandRemote::CommandRemote()
{
    boot();
}


CommandRemote::~CommandRemote() {}


void CommandRemote::boot()
{
    m_buttons[Save::getAlias()] = configure<Save>();
    m_buttons[Load::getAlias()] = configure<Load>();
    m_buttons[Pair::getAlias()] = configure<Pair>();
    m_buttons[New::getAlias()] = configure<New>();
    m_buttons[List::getAlias()] = configure<List>();
    m_buttons[Dup::getAlias()] = configure<Dup>();
}


std::unique_ptr<Command> CommandRemote::request(const std::string &command,
                                                std::vector<std::string> args)
{
    if ( m_buttons.find(command) != m_buttons.end())
        return m_buttons.find(command)->second.first(args);
    else
        throw InvalidCommand(command);
}


std::string CommandRemote::getHelp() const
{
    Buttons::const_iterator it;

    std::string helpString(HELP_TITLE);

    for ( it = m_buttons.begin();
          it != m_buttons.end();
          helpString += getHelp(it->first) + SEPARATOR );

    return helpString;
}


std::string CommandRemote::getHelp(const std::string &command) const
{

    if ( m_buttons.find(command) != m_buttons.end())
        return m_buttons.find(command)->second.second;

    throw InvalidCommand(command);
}


