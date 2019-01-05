//
// Created by Rabia on 04/01/2019.
//

#ifndef DNA_ANALYZER_TOOMANYARGUMENTSEXCEPTION_H
#define DNA_ANALYZER_TOOMANYARGUMENTSEXCEPTION_H


#include <exception>

class TooManyArgumentsException : public std::exception
{
    virtual const char *what () const throw ()
    {
        return "DNA Analyzer: Too many arguments";
    }
};


#endif //DNA_ANALYZER_TOOMANYARGUMENTSEXCEPTION_H
