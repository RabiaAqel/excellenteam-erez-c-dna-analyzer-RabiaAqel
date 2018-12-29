#include <iostream>


#include "CLI.h"
#include "CommandParser.h"
#include "CommandRemote.h"
#include "Controller.h"


int main ()
{
    // Remote for supported commands
    std::shared_ptr<Remote> remote (new CommandRemote ());

    // Instance of ui
    std::shared_ptr<UI> ui (new CLI ());

    // Command parser
    std::shared_ptr<CommandParser> parser (new CommandParser ());

    // Pass entities to controller
    std::unique_ptr<Controller> controller (new Controller (remote, ui, parser));

    // start controller
    controller->start ();

    return 0;
}
