//
// Created by Rabia on 28/12/2018.
//

#include "SaveCommand.h"
#include "../../FileIO/FileWriter.h"
#include <iostream>


const std::string SaveCommand::COMMAND_NAME = "save";

SaveCommand::SaveCommand (std::vector<std::string> args)
        : command_alias (COMMAND_NAME), m_args (args) {}


SaveCommand::~SaveCommand () {}


std::string SaveCommand::execute (std::shared_ptr<DnaContainer> container)
{
    FileWriter fileWriter = FileWriter ();

    std::string fileName = m_args[1];
    std::string fileContent = m_args[0];

    fileWriter.writeFile (const_cast<char *>(fileName.c_str ()),
                          const_cast<char *>(fileContent.c_str ()));

    return "Excuting SaveCommand...";
}

