//
// Created by Rabia on 26/12/2018.
//

#ifndef DNA_ANALYZER_UI_H
#define DNA_ANALYZER_UI_H

#include <string>

class UI
{

public:
    UI () {};
    virtual ~UI () {};

    virtual void render (std::string out) = 0;
    virtual void renderError (std::string error) = 0;

    virtual std::string prompt () = 0;

};


#endif //DNA_ANALYZER_UI_H
