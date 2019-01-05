//
// Created by Rabia on 31/12/2018.
//

#ifndef DNA_ANALYZER_DNAFILE_H
#define DNA_ANALYZER_DNAFILE_H

#include <string>
#include "DnaSequence/DnaSequence.h"


class DnaFile
{

public:
    DnaFile(std::shared_ptr<DnaSequence>);
    DnaFile(const std::string& name, std::shared_ptr<DnaSequence>);

private:
    std::string m_name;
    static size_t m_id;

    std::shared_ptr<DnaSequence> m_sequence;
};


#endif //DNA_ANALYZER_DNAFILE_H
