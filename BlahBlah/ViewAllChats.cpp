#include "ViewAllChats.h"
// Nikolay Stoyanov 2MI0600435

#include <iostream>


void ViewAllChats::execute() const
{
    const User* currentUser = usersRepository->getCurrentUserConst();

    if (!currentUser)
    {
        std::cout << "You are not logged in.\n";
        return;
    }

    if (!currentUser->isAdmin())
    {
        std::cout << "You have no permissions to access this information.\n";
        return;
    }

    const Vector<Chat*> chats = chatsRepository->getChats();

    if (chats.empty())
    {
        std::cout << "There are no chats.\n";
        return;
    }

    std::cout << "Chats:\n";

    for (uint32_t i = 0; i < chats.size(); i++)
    {
        std::cout << chats[i]->getId() << ": ";
        std::cout << chats[i]->getDisplayName() << '\n';
    }
}

bool ViewAllChats::validateInput() const
{
    return true;
}
