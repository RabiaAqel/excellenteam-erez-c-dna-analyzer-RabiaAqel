//

// Created by Rabia on 04/01/2019.
//

#ifndef DNA_ANALYZER_INVALIDARGUMENT_H
#define DNA_ANALYZER_INVALIDARGUMENT_H


#include <stdexcept>
#include <string>

namespace TwoEngine
{

    class InvalidArgument : public std::runtime_error
    {
    public:
        InvalidArgument(const std::string &which)
                : runtime_error(""), m_which(which) {};

        ~InvalidArgument() _NOEXCEPT {};

        virtual const char *what() const throw()
        {
            std::string message = "";

            message = "DNA Analyzer: Invalid argument: " + m_which;

            return message.c_str();
        }

    private:
        std::string m_which;

    };

}
#endif //DNA_ANALYZER_INVALIDARGUMENT_H
