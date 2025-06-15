// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "CreateAdmin.h"
#include "AdminUser.h"

CreateAdmin::CreateAdmin(const String& username, const String& password)
	:username(username), password(password) {}

void CreateAdmin::execute() const
{
	if (usersRepository->getCurrentUserConst())
	{
		std::cout << "User is logged. Log out to register as a new user!\n";
		return;
	}

	if (!validateInput())
	{
		return;
	}

	AdminUser user(this->username, this->password, AdminUser::getNextAdminCode());

	usersRepository->addUser(user);
	std::cout << "Account created!\n";
}

bool CreateAdmin::validateInput() const
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

	if (usersRepository->isUsernameTaken(this->username))
	{
		std::cout << "Username is taken. Try another one.\n";
		return false;
	}

	return true;
}