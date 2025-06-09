// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "ChatSystem.h"
#include "CommandFactory.h"
#include "String.h"

void ChatSystem::run()
{
    std::cout << "Welcome to BlahBlah! \n";

    CommandFactory* commandFactory = CommandFactory::getInstance();
    UsersRepository* usersRepository = UsersRepository::getInstance();

    usersRepository->loadFromTextFile();

    while (true)
    {
        String line;
        getline(std::cin, line);
        if (line.contains("exit"))
        {
            break;
        }

        Command* command = commandFactory->readCommand(line);

        if (!command)
        {
            std::cout << "Invalid command! If you need assistance, type get-help \n";
            continue;
        }

        command->execute();

        delete command;
    }

    usersRepository->saveToTextFile();

    CommandFactory::freeInstance();
}
