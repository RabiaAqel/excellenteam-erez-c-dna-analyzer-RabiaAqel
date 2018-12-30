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
const std::string LoadCommand::ARGS_FORMAT = "^([\\s]*([A-Za-z0-9-_]+\\.rawdna)[\\s]*(@([A-Za-z0-9-_]+))?)$";


LoadCommand::LoadCommand (std::vector<std::string> args)
        : command_alias (COMMAND_NAME), m_args (args)
{}


LoadCommand::~LoadCommand ()
{}


std::string LoadCommand::execute (std::shared_ptr<DnaContainer> container)
{
    // TODO: Deal with memory leak at line 36!!!
    FileReader fileReader;

    std::string fileName = m_args.front ();

    char *data = (char *) malloc (sizeof (char) * MAXBUFLEN);

    data = strcpy (data, fileReader.readFile (const_cast<char *>(fileName.c_str ())));

    container->insert (std::shared_ptr<DnaSequence> (new DnaSequence (data)));

    free(data);

    return "success";
}


