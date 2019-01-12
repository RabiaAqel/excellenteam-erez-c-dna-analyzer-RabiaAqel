//
// Created by Rabia on 30/12/2018.
//

#ifndef DNA_ANALYZER_DNACONTAINER_H
#define DNA_ANALYZER_DNACONTAINER_H

#include <map>
#include <iostream>

#include "ActiveDnaSequence.h"
#include "../Exceptions/SequenceDoesntExist.h"

class DnaContainer
{
public:

    DnaContainer();

    ~DnaContainer() {};


    size_t insert(std::string sequenceName,
                  const std::string &data,
                  const char state);

    size_t insert(const std::string &data,
                  const char state);

    std::shared_ptr<ActiveDnaSequence> findByName(std::string);

    std::shared_ptr<ActiveDnaSequence> findByID(size_t);


    std::string getList() const;

    bool exists(const std::string &sequenceName) const;
    bool exists(size_t id) const;

    const std::string getSequenceString(const std::string &sequenceName) const;

    void pair(const std::string &name);

    void pair(size_t id);


private:

    std::map<std::string, std::shared_ptr<ActiveDnaSequence> > m_nameMap;
    std::map<size_t, std::shared_ptr<ActiveDnaSequence> > m_idMap;

    static size_t m_currentID;

};


#endif //DNA_ANALYZER_DNACONTAINER_H
