//
// Created by Rabia on 28/12/2018.
//

#include <cstring>
#include <string>

#include "LoadCommand.h"
#include "../../FileIO/FileReader.h"

// TODO: Get rid of define!!!!
#define MAXBUFLEN 1000000

const std::string LoadCommand::COMMAND_NAME = "load";


LoadCommand::LoadCommand (std::vector<std::string> args)
        : command_alias (COMMAND_NAME), m_args (args)
{
    size_t args_count = m_args.size ();

    if ( args_count > MAX_ARGS )
        throw TooManyArgumentsException ();
    if ( args_count < MIN_ARGS )
        throw TooFewArgumentsException ();
}


LoadCommand::~LoadCommand () {}


void LoadCommand::execute (std::shared_ptr<DnaContainer> container)
{
    // TODO: Deal with memory leak at line 36!!!
    FileReader fileReader;

    std::string fileName = m_args.front ();

    char *data = (char *) malloc (sizeof (char) * MAXBUFLEN);

    data = strcpy (data, fileReader.readFile (const_cast<char *>(fileName.c_str ())));

    std::string sequenceName (m_args[1]);

    if ( m_args.size () == MAX_ARGS )
        container->insert (sequenceName.erase (0, 1), data);
    else
        container->insert (data);

    if ( strlen (data) > 40 )
    {
        std::string viewStr (data);
        m_response = viewStr.substr (0, 37) + "..." + viewStr.substr (viewStr.length () - 3, viewStr.length () - 1);
    }
    else
    {
        m_response = data;
    }

    free (data);
}


const std::string &LoadCommand::getResponse () const
{
    return m_response;
}

