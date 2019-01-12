//
// Created by Rabia on 12/01/2019.
//

#ifndef DNA_ANALYZER_RAWDNAFILENOTFOUND_H
#define DNA_ANALYZER_RAWDNAFILENOTFOUND_H

#include <stdexcept>
#include <string>


class RawDnaNotFound : public std::runtime_error
{
public:
    RawDnaNotFound(const std::string &which)
            : runtime_error(""), m_which(which) {};

    ~RawDnaNotFound() _NOEXCEPT {};

    virtual const char *what() const throw()
    {
        std::string message = "";

        message = "DNA Analyzer: rawdna file not found: " + m_which;

        return message.c_str();
    }

private:
    std::string m_which;

};


#endif //DNA_ANALYZER_RAWDNAFILENOTFOUND_H
