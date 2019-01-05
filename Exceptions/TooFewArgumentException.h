//
// Created by Rabia on 04/01/2019.
//

#ifndef DNA_ANALYZER_TOOFEWARGUMENTEXCEPTION_H
#define DNA_ANALYZER_TOOFEWARGUMENTEXCEPTION_H


#include <exception>

class TooFewArgumentsException : public std::exception
{
    virtual const char *what () const throw ()
    {
        return "DNA Analyzer: Too few arguments";
    }
};


#endif //DNA_ANALYZER_TOOFEWARGUMENTEXCEPTION_H
