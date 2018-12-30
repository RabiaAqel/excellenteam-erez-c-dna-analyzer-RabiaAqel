//
// Created by Rabia on 25/10/2018.
//

#ifndef DNA_TASK_DNASEQUENCE_H
#define DNA_TASK_DNASEQUENCE_H

#include <string>
#include <iostream>

#include "Nucleotide.h"

class DnaSequence {

public:

    explicit DnaSequence(const char* sequence);
    explicit DnaSequence(const std::string& sequence);
    DnaSequence(const DnaSequence& other);
    ~DnaSequence ();

    DnaSequence& operator=(const char* const sequence);
    DnaSequence& operator=(const std::string& sequence);
    DnaSequence& operator=(const DnaSequence& other);

    friend std::ostream& operator<< (std::ostream &os, const DnaSequence &dna);

    bool operator== (const DnaSequence& other);
    bool operator!= (const DnaSequence& other);

    const Nucleotide operator[] (int index) const; // const should not return ref
    Nucleotide& operator[] (int index); // not const should return ref to change - (const char doesnt make sense)


    size_t getLength() const;

    size_t slice(Nucleotide* slice, size_t from, size_t to);

    DnaSequence& paired() const;

    long find(const std::string& sub, size_t from);

private:

    mutable size_t m_length;
    Nucleotide* m_sequence;

    void copySequenceFromChars
    (const char* sequence, size_t len);
    void copySequenceFromNucleotides
    (const Nucleotide* sequence, size_t len);

};

inline DnaSequence::~DnaSequence ()
{
    delete[] m_sequence;
}


inline bool DnaSequence::operator!= (const DnaSequence &other)
{
    return !(*this == other);
}


inline Nucleotide& DnaSequence::operator[] (int index)
{
   return m_sequence[index];
}


// since the returned char is by value, changing it
// wont change it actually.
// using const char is recommended to produce
// compilation error (protects users)
inline const Nucleotide DnaSequence::operator[] (int index) const
{
    return m_sequence[index];
}


inline size_t DnaSequence::getLength () const
{
    return m_length;
}



inline DnaSequence& DnaSequence::operator=(const std::string& sequence)
{
    *this = sequence.c_str();
    return *this;
}



#endif //DNA_TASK_DNASEQUENCE_H

