//
// Created by Rabia on 28/12/2018.
//


#include <iostream>
#include "CommandRemote.h"
#include "../Exceptions/InvalidCommandException.h"
#include "../Command/Management/SaveCommand.h"
#include "../Command/CreationCommand/LoadCommand.h"
#include "../Command/Control/ListCommand.h"
#include "../Command/Manipulation/PairCommand.h"


CommandRemote::CommandRemote () {}


CommandRemote::~CommandRemote () {}


void CommandRemote::boot () {}


std::unique_ptr<Command> CommandRemote::request (const std::string &command_name,
                                                 std::vector<std::string> args)
{
    std::string SAVE = "save";
    std::string LOAD = "load";
    std::string LIST = "list";
    std::string PAIR = "pair";

    std::string response;

    if (command_name == SAVE)
        return std::unique_ptr<Command> (new SaveCommand (args));
    else if (command_name == LOAD)
        return std::unique_ptr<Command> (new LoadCommand (args));
    else if  (command_name == LIST)
        return std::unique_ptr<Command> (new ListCommand(args));
    else if  (command_name == PAIR)
        return std::unique_ptr<Command> (new PairCommand(args));
    else
        throw InvalidCommandException ();
}