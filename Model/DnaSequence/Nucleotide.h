//
// Created by Rabia on 28/10/2018.
//

#ifndef DNA_TASK_NUCLEOTIDE_H
#define DNA_TASK_NUCLEOTIDE_H

#include <iostream>

class Nucleotide
{

public:

    explicit Nucleotide(char c);

    Nucleotide(const Nucleotide &other);

    explicit Nucleotide() : m_nucleotide() {};

    ~Nucleotide() {};

    Nucleotide &operator=(const Nucleotide &other);

    Nucleotide &operator=(char c);

    bool operator==(char c);

    bool operator!=(char c);

    char &getNucleotide();

    const char getNucleotide() const;

private:

    char m_nucleotide;

    bool isValid(char c);

    static const std::string INVALID_MSG;

};


inline Nucleotide::Nucleotide(char c)
{
    if ( isValid(c))
        m_nucleotide = c;
    else
        throw std::invalid_argument(INVALID_MSG);
}


inline Nucleotide::Nucleotide(const Nucleotide &other)
{
    m_nucleotide = other.m_nucleotide;
}


inline Nucleotide &Nucleotide::operator=(const Nucleotide &other)
{
    if ( this == &other )
        return *this;

    m_nucleotide = other.getNucleotide();

    return *this;
}


inline Nucleotide &Nucleotide::operator=(char c)
{
    if ( isValid(c))
        m_nucleotide = c;
    else
        throw std::invalid_argument(INVALID_MSG);

    return *this;
}


inline char &Nucleotide::getNucleotide()
{
    return m_nucleotide;
}


inline const char Nucleotide::getNucleotide() const
{
    return m_nucleotide;
}


inline bool Nucleotide::isValid(char c)
{
    return (c == 'A' || c == 'G' || c == 'C' || c == 'T');
}

inline bool Nucleotide::operator==(char c)
{
    return (m_nucleotide == c);
}

inline bool Nucleotide::operator!=(char c)
{
    return (m_nucleotide != c);
}


#endif //DNA_TASK_NUCLEOTIDE_H
