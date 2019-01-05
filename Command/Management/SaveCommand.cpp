//
// Created by Rabia on 28/12/2018.
//

#include "SaveCommand.h"
#include "../../FileIO/FileWriter.h"
#include <iostream>


const std::string SaveCommand::COMMAND_NAME = "save";

SaveCommand::SaveCommand (std::vector<std::string> args)
        : command_alias (COMMAND_NAME), m_args (args)
{
    size_t args_count = m_args.size ();

    if ( args_count > MAX_ARGS )
        throw TooManyArgumentsException ();
    if ( args_count < MIN_ARGS )
        throw TooFewArgumentsException ();
}


SaveCommand::~SaveCommand () {}


void SaveCommand::execute (std::shared_ptr<DnaContainer> container)
{
    FileWriter fileWriter = FileWriter ();

    std::string sequenceName (m_args[0]);
    std::cout << container->getSequenceString (sequenceName).c_str () << std::endl;

    try
    {

        if ( m_args.size () == MAX_ARGS )
        {
            fileWriter.writeFile (const_cast<char *>(sequenceName.c_str ()),
                                  const_cast<char *>(container->getSequenceString (sequenceName).c_str ()));
        }
        else
        {
            fileWriter.writeFile (const_cast<char *>(generateName ().c_str ()),
                                  const_cast<char *>(container->getSequenceString (sequenceName).c_str ()));
        }

    }
    catch ( SequenceDoesntExist &e )
    {
        throw e;
    }

    m_response = "Excuting SaveCommand...";
}


const std::string SaveCommand::generateName ()
{
    m_response = m_args[0] + ".rawdna";
}

const std::string &SaveCommand::getResponse () const
{
    return m_response;
}

