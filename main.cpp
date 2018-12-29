#include <iostream>


#include "CLI.h"

#include "CommandParser.h"
#include "CommandRemote.h"
#include "Controller.h"


int main ()
{
    std::shared_ptr<Remote> remote (new CommandRemote ());
    std::shared_ptr<UI> ui (new CLI ());
    std::shared_ptr<CommandParser> parser (new CommandParser ());

    std::unique_ptr<Controller> controller (new Controller (remote, ui, parser));

    controller->start ();

    return 0;
}
