//
// Created by Rabia on 29/12/2018.
//

#ifndef DNA_ANALYZER_INVALIDCOMMAND_H
#define DNA_ANALYZER_INVALIDCOMMAND_H

#include <stdexcept>
#include <string>


    class InvalidCommand : public std::runtime_error
    {
    public:
        InvalidCommand(const std::string &which)
                : runtime_error(""), m_which(which) {};

        ~InvalidCommand() _NOEXCEPT {};


        virtual const char *what() const throw()
        {
            std::string message = "";

            message = "DNA Analyzer: Command not found: " + m_which;

            return message.c_str();
        }

    private:
        std::string m_which;


    };


#endif //DNA_ANALYZER_INVALIDCOMMAND_H
