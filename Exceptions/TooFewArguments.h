//
// Created by Rabia on 04/01/2019.
//

#ifndef DNA_ANALYZER_TOOFEWARGUMENTS_H
#define DNA_ANALYZER_TOOFEWARGUMENTS_H


#include <stdexcept>
#include <string>

namespace DnaAnalyzerExceptions
{

    class TooFewArguments : public std::runtime_error
    {
    public:
        TooFewArguments(const std::string &which)
                : runtime_error(""), m_which(which) {};

        ~TooFewArguments() _NOEXCEPT {};

        virtual const char *what() const throw()
        {
            std::string message = "";

            message = "DNA Analyzer: Too few arguments for: " + m_which;

            return message.c_str();
        }

    private:
        std::string m_which;
    };

}

#endif //DNA_ANALYZER_TOOFEWARGUMENTS_H
