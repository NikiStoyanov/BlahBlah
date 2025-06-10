// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "Login.h"
#include "RegularUser.h"

Login::Login(const String& username, const String& password)
	: username(username), password(password) {}

void Login::execute() const
{
	if (usersRepository->getCurrentUserConst())
	{
		std::cout << "User is already logged in.\n";
		return;
	}

	if (!validateInput())
	{
		return;
	}

	User* user = usersRepository->findByUsername(username);

	if (!user) 
	{
		std::cout << "Account not found. Create? (y/n)\n";
		return;
	}

	if (!user->checkPassword(password))
	{
		std::cout << "Wrong credentials!\n";
		return;
	}

	usersRepository->setCurrentUser(user);
	std::cout << "Welcome, " << user->getUsername() << "!\n";
}

bool Login::validateInput() const
{
	if (this->username.empty())
	{
		std::cout << "Username could not be empty.\n";
		return false;
	}

	if (this->password.empty())
	{
		std::cout << "Password should be at least 1 character.\n";
		return false;
	}

	return true;
}


// int32_t ChatSystem::login(const char* username, const char* password)
// {
// 	for (uint32_t i = 0; i < usersCount; i++)
// 	{
// 		bool isUsernameMatch = Utils::compareStrings(this->users[i].getUsername(), username);
//
// 		if (isUsernameMatch)
// 		{
// 			bool isPasswordMatch = this->users[i].checkPassword(password);
// 			if (isPasswordMatch)
// 			{
// 				this->currentUser = &this->users[i];
// 				return 1;
// 			}
// 			else
// 			{
// 				return 0;
// 			}
// 		}
// 	}
//
// 	return -1;
// 	std::cout << "Account not found. Create? (y/n)";
// }