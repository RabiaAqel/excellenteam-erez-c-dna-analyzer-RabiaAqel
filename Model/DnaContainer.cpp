
#include <sstream>

#include "DnaContainer.h"


size_t DnaContainer::m_currentID = 0;


DnaContainer::DnaContainer()
{
}


size_t DnaContainer::
insert(std::string name,
       const std::string &data,
       char state)
{
    std::shared_ptr<ActiveDnaSequence>
            activeDna(new ActiveDnaSequence(data, name, state));

    m_nameMap.insert(std::pair<std::string,
            std::shared_ptr<ActiveDnaSequence> >
                             (name, activeDna));

    m_idMap.insert(std::pair<size_t,
            std::shared_ptr<ActiveDnaSequence> >
                           (activeDna->getID(), activeDna));

    return activeDna->getID();
}


size_t DnaContainer::
insert(const std::string &data,
       const char state)
{

    std::shared_ptr<ActiveDnaSequence>
            activeDna(new ActiveDnaSequence(data, state));

    m_nameMap.insert(std::pair<std::string,
            std::shared_ptr<ActiveDnaSequence> >
                             (activeDna->getName(), activeDna));

    m_idMap.insert(std::pair<size_t,
            std::shared_ptr<ActiveDnaSequence> >
                           (activeDna->getID(), activeDna));

    return activeDna->getID();
}


std::shared_ptr<ActiveDnaSequence> DnaContainer::
findByName(std::string sequenceName)
{
    if ( exists(sequenceName))
        return m_nameMap[sequenceName];
    else
        throw SequenceDoesntExist(sequenceName);
}


std::shared_ptr<ActiveDnaSequence> DnaContainer::
findByID(size_t id)
{
    if ( exists(id))
        return m_idMap[id];
    else
        throw SequenceDoesntExist("#" + std::to_string(id));

}


std::string DnaContainer::getList() const
{
    std::stringstream ss;
    typedef std::map<size_t, std::shared_ptr<ActiveDnaSequence> > idIterator;
    typedef std::map<std::string, std::shared_ptr<ActiveDnaSequence> > nameIterator;

    idIterator::const_iterator it = m_idMap.begin();
    nameIterator::const_iterator it2 = m_nameMap.begin();

    while ( it != m_idMap.end() && it2 != m_nameMap.end())
    {
        ss << *it->second;
        ++it;
        ++it2;
    }

    return ss.str();
}


bool DnaContainer::exists(const std::string &sequenceName) const
{
    return m_nameMap.find(sequenceName) != m_nameMap.end();
}

bool DnaContainer::exists(size_t id) const
{
    return m_idMap.find(id) != m_idMap.end();
}


const std::string DnaContainer::getSequenceString(const std::string &name) const
{

    if ( !exists(name))
        throw SequenceDoesntExist(name);
    else
        return (m_nameMap.find(name)->second)->toString();

}


void DnaContainer::pair(const std::string &name)
{
    if ( !exists(name))
        throw SequenceDoesntExist(name);
    else
        (m_nameMap.find(name)->second)->pair();

}


void DnaContainer::pair(size_t id)
{
    if ( !exists(id))
        throw SequenceDoesntExist("#" + std::to_string(id));
    else
        (m_idMap.find(id)->second)->pair();


}

