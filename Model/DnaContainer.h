//
// Created by Rabia on 30/12/2018.
//

#ifndef DNA_ANALYZER_DNACONTAINER_H
#define DNA_ANALYZER_DNACONTAINER_H

#include <map>
#include <iostream>

#include "DnaSequence/DnaSequence.h"


class DnaContainer
{
public:

    DnaContainer();
    ~DnaContainer () {};


    bool insert (std::string sequenceName, std::shared_ptr<DnaSequence> sequence);
    bool insert (std::shared_ptr<DnaSequence> sequence);

    std::shared_ptr<DnaSequence> findByName (std::string);

    std::shared_ptr<DnaSequence> findByID (size_t);

    static size_t generateID();
    static std::string generateName();

    std::string getList() const;


private:

    std::map<std::string, std::shared_ptr<DnaSequence> > m_nameMap;
    std::map<size_t, std::shared_ptr<DnaSequence> > m_idMap;

    static size_t m_currentID;

};



#endif //DNA_ANALYZER_DNACONTAINER_H
