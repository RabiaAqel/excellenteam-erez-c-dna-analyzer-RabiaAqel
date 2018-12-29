//
// Created by Rabia on 28/12/2018.
//


#include <iostream>
#include "CommandRemote.h"
#include "Exceptions/InvalidCommandException.h"
#include "Command/SaveCommand.h"
#include "Command/LoadCommand.h"


CommandRemote::CommandRemote () {}


CommandRemote::~CommandRemote () {}


void CommandRemote::boot () {}


std::unique_ptr<Command> CommandRemote::request (const std::string &command_name,
                                                 std::vector<std::string> args)
{
    std::string SAVE = "save";
    std::string LOAD = "load";

    std::string response;

    if (command_name == SAVE)
        return std::unique_ptr<Command> (new SaveCommand (args));
    else if (command_name == LOAD)
        return std::unique_ptr<Command> (new LoadCommand (args));
    else
        throw InvalidCommandException ();
}