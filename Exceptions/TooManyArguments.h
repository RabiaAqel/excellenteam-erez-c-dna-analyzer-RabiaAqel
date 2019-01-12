//
// Created by Rabia on 04/01/2019.
//

#ifndef DNA_ANALYZER_TOOMANYARGUMENTS_H
#define DNA_ANALYZER_TOOMANYARGUMENTS_H


#include <stdexcept>
#include <string>


class TooManyArguments : public std::runtime_error
{
public:
    TooManyArguments(const std::string &which)
            : runtime_error(""), m_which(which) {};

    ~TooManyArguments() _NOEXCEPT {};

    virtual const char *what() const throw()
    {
        std::string message = "";

        message = "DNA Analyzer: Too many arguments for: " + m_which;

        return message.c_str();
    }

private:
    std::string m_which;
};


#endif //DNA_ANALYZER_TOOMANYARGUMENTS_H
