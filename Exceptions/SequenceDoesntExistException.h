//
// Created by Rabia on 04/01/2019.
//

#ifndef DNA_ANALYZER_SEQUENCEDOESNTEXISTEXCEPTION_H
#define DNA_ANALYZER_SEQUENCEDOESNTEXISTEXCEPTION_H

#include <exception>

class SequenceDoesntExist : public std::exception
{
    virtual const char *what () const throw ()
    {
        return "DNA Analyzer: Sequence doesnt exist";
    }
};


#endif //DNA_ANALYZER_SEQUENCEDOESNTEXISTEXCEPTION_H
