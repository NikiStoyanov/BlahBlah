// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "Logout.h"

void Logout::execute() const
{
    const User* currentUser = usersRepository->getCurrentUserConst();

    if (!currentUser)
    {
        std::cout << "You are already logged out!\n";
        return;
    }

    std::cout << "Goodbye, " << currentUser->getUsername() << "!\n";

    usersRepository->setCurrentUser(nullptr);

    usersRepository->saveToTextFile();
    chatsRepository->saveToTextFiles();
}

bool Logout::validateInput() const
{
	return true;
}
