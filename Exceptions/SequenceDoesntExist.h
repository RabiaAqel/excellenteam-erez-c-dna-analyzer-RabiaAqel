//
// Created by Rabia on 04/01/2019.
//

#ifndef DNA_ANALYZER_SEQUENCEDOESNTEXIST_H
#define DNA_ANALYZER_SEQUENCEDOESNTEXIST_H

#include <stdexcept>
#include <string>


namespace DnaAnalyzerExceptions
{


    class SequenceDoesntExist : public std::runtime_error
    {
    public:
        SequenceDoesntExist(const std::string &which)
                : runtime_error(""), m_which(which) {};

        ~SequenceDoesntExist() _NOEXCEPT {};


        virtual const char *what() const throw()
        {
            std::string message = "";

            message = "DNA Analyzer: Sequence doesnt exist: " + m_which;

            return message.c_str();

        };

    private:
        std::string m_which;
    };

}

#endif //DNA_ANALYZER_SEQUENCEDOESNTEXIST_H
