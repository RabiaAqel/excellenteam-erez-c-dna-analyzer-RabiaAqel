//
// Created by Rabia on 28/12/2018.
//

#include <cstring>
#include <string>
#include <sstream>

#include "LoadCommand.h"
#include "../../FileIO/FileReader.h"

// TODO: Get rid of define!!!!
#define MAXBUFLEN 1000000

const std::string LoadCommand::COMMAND_ALIAS = "load";
const std::string LoadCommand::HELP = "usage: load <file_name>  [@<sequence_name>]";


LoadCommand::LoadCommand(std::vector<std::string> args)
        : m_args(args)
{
    size_t args_count = m_args.size();

    if ( args_count > MAX_ARGS )
        throw DnaAnalyzerExceptions::TooManyArguments(COMMAND_ALIAS);
    if ( args_count < MIN_ARGS )
        throw DnaAnalyzerExceptions::TooFewArguments(COMMAND_ALIAS);
}


LoadCommand::~LoadCommand() {}


void LoadCommand::execute(std::shared_ptr<DnaContainer> container)
{
    // TODO: Deal with memory leak at line 36!!!
    FileReader fileReader;

    std::string fileName = m_args.front();

    std::string content = "";

    content = fileReader.readFile(const_cast<char *>(fileName.c_str()));

    if ( content.empty())
        throw DnaAnalyzerExceptions::RawDnaNotFound((!fileName.empty()) ? fileName : "No file provided!");

    std::string sequenceName(m_args[1]);

    size_t id;

    std::stringstream ss;

    if ( m_args.size() == MAX_ARGS )
        id = container->insert(sequenceName.erase(0, 1), content, '-');
    else
        id = container->insert(content, '-');

    ss << *container->findByID(id);

    m_response = ss.str();


}


const std::string &LoadCommand::getResponse() const
{
    return m_response;
}

