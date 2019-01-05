
#include "DnaContainer.h"


size_t DnaContainer::m_currentID = 0;

DnaContainer::DnaContainer ()
{
}

bool DnaContainer::
insert (std::string sequenceName,
        const std::string& data)
{
    std::shared_ptr<DnaSequence> dnaSequence(new DnaSequence(data));
    m_nameMap.insert (std::pair<std::string, std::shared_ptr<DnaSequence> > (sequenceName, dnaSequence));
    m_idMap.insert (std::pair<size_t, std::shared_ptr<DnaSequence> > (generateID (), dnaSequence));
}


bool DnaContainer::
insert (const std::string& data)
{
    std::shared_ptr<DnaSequence> dnaSequence(new DnaSequence(data));
    m_nameMap.insert (std::pair<std::string, std::shared_ptr<DnaSequence> > (generateName (), dnaSequence));
    m_idMap.insert (std::pair<size_t, std::shared_ptr<DnaSequence> > (generateID (), dnaSequence));
}


std::shared_ptr<DnaSequence> DnaContainer::
findByName (std::string sequenceName)
{
    if (m_nameMap.find (sequenceName) != m_nameMap.end ())
        return m_nameMap[sequenceName];
}


std::shared_ptr<DnaSequence> DnaContainer::
findByID (size_t id)
{
    if (m_idMap.find (id) != m_idMap.end ())
        return m_idMap[id];
}


size_t DnaContainer::generateID ()
{
    return ++m_currentID;
}


std::string DnaContainer::generateName ()
{
    return "seq" + std::to_string (m_currentID + 1);
}


std::string DnaContainer::getList () const
{
    std::string list = "";
    typedef std::map<size_t, std::shared_ptr<DnaSequence> > idIterator;
    typedef std::map<std::string, std::shared_ptr<DnaSequence> > nameIterator;

    idIterator::const_iterator it = m_idMap.begin ();
    nameIterator::const_iterator it2 = m_nameMap.begin ();

    while (it != m_idMap.end () && it2 != m_nameMap.end ())
    {
        list += "[" + std::to_string (it->first) + "] " + it2->first + "\n";
        ++it;
        ++it2;
    }

    return list;
}


bool DnaContainer::exists(const std::string& sequenceName) const
{
    return m_nameMap.find(sequenceName) != m_nameMap.end();
}


const std::string DnaContainer::getSequenceString(const std::string& sequenceName) const
{

    if (!exists (sequenceName))
        throw SequenceDoesntExist();
    else
        return (m_nameMap.find(sequenceName)->second)->toString ();

}