//
// Created by Rabia on 28/12/2018.
//

#include "Save.h"
#include "../../FileIO/FileWriter.h"
#include <iostream>


const std::string Save::COMMAND_ALIAS = "save";
const std::string Save::HELP = "usage: save <seq> [<filename>]";

Save::Save(std::vector<std::string> args)
        : m_args(args)
{
    size_t args_count = m_args.size();

    if ( args_count > MAX_ARGS )
        throw TooManyArguments(COMMAND_ALIAS);
    if ( args_count < MIN_ARGS )
        throw TooFewArguments(COMMAND_ALIAS);
}


Save::~Save() {}


void Save::execute(std::shared_ptr<DnaContainer> container)
{
    FileWriter fileWriter = FileWriter();

    std::string sequenceName(m_args[0]);

    try
    {

        if ( m_args.size() == MAX_ARGS )
        {
            fileWriter.writeFile(const_cast<char *>(sequenceName.c_str()),
                                 const_cast<char *>(container->getSequenceString(sequenceName).c_str()));
        }
        else
        {
            fileWriter.writeFile(const_cast<char *>(generateName().c_str()),
                                 const_cast<char *>(container->getSequenceString(sequenceName).c_str()));
        }

    }
    catch ( SequenceDoesntExist &e )
    {
        throw e;
    }

    m_response = "Excuting Save...";
}


const std::string Save::generateName()
{
    return m_args[0] + ".rawdna";
}


const std::string &Save::getResponse() const
{
    return m_response;
}
