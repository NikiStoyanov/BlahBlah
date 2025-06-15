// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "ViewChats.h"

void ViewChats::execute() const
{
    const User* currentUser = usersRepository->getCurrentUserConst();

    if (!currentUser)
    {
        std::cout << "You are not logged in.\n";
        return;
    }

    const Vector<Chat*> chats = currentUser->getChats();

    if (chats.empty())
    {
        std::cout << "You have no chats.\n";
        return;
    }

    std::cout << "Chats:\n";

    for (uint32_t i = 0; i < chats.size(); ++i)
    {
        const Vector<String>& members = chats[i]->getMembers();

        std::cout << chats[i]->getId() << ": ";

        bool first = true;
        for (uint32_t j = 0; j < members.size(); j++)
        {
            if (members[j] != currentUser->getUsername())
            {
                if (!first)
                    std::cout << ", ";

                std::cout << members[j];
                first = false;
            }
        }

        std::cout << "\n";
    }
}

bool ViewChats::validateInput() const
{
	return true;
}
