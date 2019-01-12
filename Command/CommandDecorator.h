//
// Created by Rabia on 12/01/2019.
//

#ifndef DNA_ANALYZER_CommandDecorator_H
#define DNA_ANALYZER_CommandDecorator_H

#include "Command.h"


class CommandDecorator : public Command
{

public:
    CommandDecorator(std::shared_ptr<Command> command)
            : m_command(command) {}


    virtual void execute(std::shared_ptr<DnaContainer> container)
    {
        m_command->execute(container);
    }


private:
    std::shared_ptr<Command> m_command;
};


#endif //DNA_ANALYZER_CommandDecorator_H
