//
// Created by Rabia on 10/01/2019.
//

#ifndef DNA_ANALYZER_ACTIVEDNASEQUENCE_H
#define DNA_ANALYZER_ACTIVEDNASEQUENCE_H

#include "DnaSequence/DnaSequence.h"


class ActiveDnaSequence
{
public:
    ActiveDnaSequence(const std::string &data,
                      const std::string &name,
                      char state);

    ActiveDnaSequence(const std::string &data,
                      char state);

    std::string toString() const;

    size_t getID() const;

    std::string getName() const;

    char getState() const;

    friend std::ostream &operator<<(std::ostream &os, const ActiveDnaSequence &dna);

private:
    std::shared_ptr<DnaSequence> m_dnaSequence;
    const size_t m_id;
    std::string m_name;
    mutable char m_state;

    static size_t m_currentID;

    static size_t generateID();

    std::string generateName();

};


inline size_t ActiveDnaSequence::generateID()
{
    return ++m_currentID;
}


inline size_t ActiveDnaSequence::getID() const
{
    return m_id;
}


inline char ActiveDnaSequence::getState() const
{
    return m_state;
}


inline std::string ActiveDnaSequence::getName() const
{
    return m_name;
}


#endif //DNA_ANALYZER_ACTIVEDNASEQUENCE_H
