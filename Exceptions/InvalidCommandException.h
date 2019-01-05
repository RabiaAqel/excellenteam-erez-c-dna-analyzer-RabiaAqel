//
// Created by Rabia on 29/12/2018.
//

#ifndef DNA_ANALYZER_INVALIDCOMMANDEXCEPTION_H
#define DNA_ANALYZER_INVALIDCOMMANDEXCEPTION_H

#include <exception>

class InvalidCommandException : public std::exception
{
    virtual const char *what () const throw ()
    {
        return "DNA Analyzer: Command not found";
    }
};


#endif //DNA_ANALYZER_INVALIDCOMMANDEXCEPTION_H
