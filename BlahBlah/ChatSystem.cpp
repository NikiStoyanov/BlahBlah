#include "ChatSystem.h"

#include <iostream>

#include "Utils.h"

void ChatSystem::run()
{
    bool running = true;
    while (running)
    {
        std::cout << "Welcome to BlahBlah!" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Register" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Choose an option: ";

        int choice = 0;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Login selected" << std::endl;
            break;

        case 2:
            std::cout << "Register selected" << std::endl;
            break;

        case 3:
            std::cout << "Quitting..." << std::endl;
            running = false;
            break;

        default:
            std::cout << "Invalid option, try again." << std::endl;
            break;
        }
    }
}

int32_t ChatSystem::login(const char* username, const char* password)
{
	for (uint32_t i = 0; i < usersCount; i++)
	{
		bool isUsernameMatch = Utils::compareStrings(this->users[i].getUsername(), username);

		if (isUsernameMatch)
		{
			bool isPasswordMatch = this->users[i].checkPassword(password);
			if (isPasswordMatch)
			{
				this->currentUser = &this->users[i];
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	return -1;
	std::cout << "Account not found. Create? (y/n)";
}
