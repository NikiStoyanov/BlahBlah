#include "LogInUser.h"

#include <iostream>

#include "RegularUser.h"

LogInUser::LogInUser(const String& username, const String& password)
{
	this->username = username;
	this->password = password;
}

void LogInUser::execute() const
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

	// uint32_t usersCount = usersRepository
	// for (uint32_t i = 0; i < user; ++i)
	// {
	// 	
	// }

	User* user = new RegularUser(this->username, this->password);

	if (user)
	{
		//usersRepository->addUser(user);
	}

	std::cout << "Account created!\n";

	delete user;
}

bool LogInUser::validateInput() const
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