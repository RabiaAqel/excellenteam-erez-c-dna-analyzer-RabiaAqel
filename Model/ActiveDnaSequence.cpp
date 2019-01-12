//
// Created by Rabia on 10/01/2019.
//

#include "ActiveDnaSequence.h"
#include <sstream>


size_t ActiveDnaSequence::m_currentID = 0;


ActiveDnaSequence::ActiveDnaSequence(const std::string &data,
                                     const std::string &name,
                                     char state)
        : m_dnaSequence(std::shared_ptr<DnaSequence>(new DnaSequence(data))),
          m_id(generateID()),
          m_name(name),
          m_state(state) {}


ActiveDnaSequence::ActiveDnaSequence(const std::string &data,
                                     char state)
        : m_dnaSequence(std::shared_ptr<DnaSequence>(new DnaSequence(data))),
          m_id(generateID()),
          m_name(generateName()),
          m_state('a') {}


ActiveDnaSequence::ActiveDnaSequence(const ActiveDnaSequence &sequence)
        : m_dnaSequence(sequence.m_dnaSequence),
          m_id(generateID()),
          m_name(sequence.m_name),
          m_state('a')
{

}


ActiveDnaSequence::ActiveDnaSequence(const ActiveDnaSequence &sequence,
                                     const std::string &name)
        : m_dnaSequence(sequence.m_dnaSequence),
          m_id(generateID()),
          m_name(name),
          m_state('a')
{

}


std::string ActiveDnaSequence::toString() const
{
    return m_dnaSequence->toString();
}


std::string ActiveDnaSequence::generateName()
{
    return "seq" + std::to_string(getID());
}


std::ostream &operator<<(std::ostream &os, const ActiveDnaSequence &dna)
{

    os << std::string(1, dna.getState());
    os << " [" << std::to_string(dna.getID()) << "] ";
    os << dna.getName() << ": ";


    std::string rawSequence = dna.toString();

    if ( rawSequence.length() > 40 )
    {
        std::string viewSequence(rawSequence);

        os << viewSequence.substr(0, 37) + "..." +
              viewSequence.substr(viewSequence.length() - 3, viewSequence.length() - 1);
    }
    else
    {
        os << rawSequence << std::endl;

    }

    return os;
}


void ActiveDnaSequence::pair()
{
    m_dnaSequence->paired();
}




