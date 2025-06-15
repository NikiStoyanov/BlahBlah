// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "ChatSystem.h"
#include "CommandFactory.h"
#include "String.h"

void ChatSystem::stop()
{
    ChatSystem::isRunning = false;
}

bool ChatSystem::running()
{
    return ChatSystem::isRunning;
}

void ChatSystem::run()
{
    std::cout << "Welcome to BlahBlah! \n";

    CommandFactory* commandFactory = CommandFactory::getInstance();
    UsersRepository* usersRepository = UsersRepository::getInstance();
    ChatsRepository* chatsRepository = ChatsRepository::getInstance();

    chatsRepository->loadFromTextFiles();
    usersRepository->loadFromTextFile();

    while (ChatSystem::running())
    {
        String line;
        getline(std::cin, line);

        Command* command = commandFactory->readCommand(line);

        if (!command)
        {
            std::cout << "Invalid command!\n";
            continue;
        }

        command->execute();

        delete command;
    }

    usersRepository->saveToTextFile();
    chatsRepository->saveToTextFiles();

    UsersRepository::freeInstance();
    ChatsRepository::freeInstance();
    CommandFactory::freeInstance();
}

bool ChatSystem::isRunning = true;