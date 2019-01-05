//

// Created by Rabia on 04/01/2019.
//

#ifndef DNA_ANALYZER_INVALIDARGUMENTEXCEPTION_H
#define DNA_ANALYZER_INVALIDARGUMENTEXCEPTION_H


#include <exception>

class InvalidArgumentException : public std::exception
{
    virtual const char *what () const throw ()
    {
        return "DNA Analyzer: Invalid argument";
    }

};


#endif //DNA_ANALYZER_INVALIDARGUMENTEXCEPTION_H
