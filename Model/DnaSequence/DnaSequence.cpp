//
// Created by Rabia on 25/10/2018.
//

#include "DnaSequence.h"

const std::string Nucleotide::INVALID_MSG = "Error: Invalid Nucleotide/s:"
                                            "" ", Cannot construct sequence.";


bool DnaSequence::operator== (const DnaSequence &other)
{
    bool res = true;

    if ( getLength () == other.getLength ())
        for ( int i = 0; i < getLength (); ++i )
            if ( m_sequence[i].getNucleotide () != other.m_sequence[i].getNucleotide ())
                res = false;

    return res;
}


DnaSequence::DnaSequence (const DnaSequence &other)
{

    size_t len = other.getLength ();

    m_length = len;


    try
    {
        m_sequence = new Nucleotide[len];
        copySequenceFromNucleotides (other.m_sequence, len);
    }
    catch ( std::invalid_argument &exception )
    {


        delete[] m_sequence;
        m_sequence = nullptr;
        throw;
    }
    catch ( std::bad_alloc &exception )
    {

        m_sequence = nullptr;
        throw;
    }
}


std::ostream &operator<< (std::ostream &os, const DnaSequence &dna)
{
    os << "DNA Sequence: ";

    os << dna.toString ();

    return os;
}


DnaSequence::DnaSequence (const char *sequence)
{
    size_t len = strlen (sequence);
    m_length = len;

    try
    {
        m_sequence = new Nucleotide[len];
        copySequenceFromChars (sequence, len);
    }
    catch ( std::invalid_argument &exception )
    {
        delete[] m_sequence;
        m_sequence = nullptr;
        throw;
    }
}


DnaSequence::DnaSequence (const std::string &sequence)
{
    size_t len = sequence.length ();
    m_sequence = new Nucleotide[len];
    m_length = len;

    try
    {
        copySequenceFromChars (sequence.c_str (), len);
    }
    catch ( std::invalid_argument &exception )
    {
        delete[] m_sequence;
        m_sequence = nullptr;
        throw;
    }
}


DnaSequence &DnaSequence::operator= (const DnaSequence &other)
{
    if ( this == &other )
        return *this;

    delete[] m_sequence;

    size_t len = other.getLength ();

    for ( int i = 0; i < len; ++i )
        other.m_sequence[i] = m_sequence[i];

    m_length = len;

    return *this;
}


DnaSequence &DnaSequence::operator= (const char *const sequence)
{
    delete[] m_sequence;

    size_t len = strlen (sequence);

    copySequenceFromChars (sequence, len);

    m_length = len;

    return *this;
}


void DnaSequence::copySequenceFromChars
        (const char *sequence, size_t len)
{
    for ( int i = 0; i < len; ++i )
        m_sequence[i] = sequence[i];
}


void DnaSequence::copySequenceFromNucleotides
        (const Nucleotide *sequence, size_t len)
{
    for ( int i = 0; i < len; ++i )
        m_sequence[i] = sequence[i];
}


size_t DnaSequence::slice (Nucleotide *slice, size_t from, size_t to)
{
    size_t len = to - from - 1;

    for ( int i = 0; i < len; ++i )
        slice[i] = m_sequence[from + i + 1];

    return len;
}

DnaSequence &DnaSequence::paired () const
{

    DnaSequence *paired = new DnaSequence (*this);

    size_t len = getLength ();

    for ( int i = 0; i < len; ++i )
    {
        if ( m_sequence[i] == 'A' )
            paired->m_sequence[i] = 'T';
        else if ( m_sequence[i] == 'T' )
            paired->m_sequence[i] = 'A';
        else if ( m_sequence[i] == 'C' )
            paired->m_sequence[i] = 'G';
        else if ( m_sequence[i] == 'G' )
            paired->m_sequence[i] = 'C';
    }

    return *paired;
}

long DnaSequence::find (const std::string &sub, size_t from)
{
    size_t sequenceLen = getLength ();
    size_t subLen = sub.length ();

    int isFound = -1;

    for ( int i = from; i < sequenceLen - subLen; ++i )
    {
        for ( int j = 0; j < subLen; ++j )
            if ( m_sequence[i + j] != sub[j] )
            {
                break;
            }
    }


    std::cout << isFound;

}


const std::string DnaSequence::toString () const
{
    std::string sequenceString = "";

    for ( int i = 0; i < getLength (); ++i )
        sequenceString += m_sequence[i].getNucleotide ();

    return sequenceString;
}