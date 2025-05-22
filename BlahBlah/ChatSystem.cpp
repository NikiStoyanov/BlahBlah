#include <iostream>

#include "ChatSystem.h"
#include "String.h"

void ChatSystem::run()
{
    std::cout << "Welcome to BlahBlah! \n";

    //CommandFactory* commandFactory = CommandFactory::getInstance();

    while (true)
    {
        String command;

        getline(std::cin, command);

        Vector<String> tokens = command.split();

        
        if (tokens[0] ==  "exit")
        {
            break;
        }

        Command* command = commandFactory->readCommand(commandText);

        if (!command)
        {
            std::cout << "---------" << std::endl;
            std::cout << "Invalid command!" << std::endl << std::endl;
            continue;
        }

        command->execute();
        delete command;
    }

    CommandFactory::freeInstance();

    do 
    {
        readCommand();

    } while (true);
}
