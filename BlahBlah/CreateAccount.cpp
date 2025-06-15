// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "CreateAccount.h"
#include "RegularUser.h"

CreateAccount::CreateAccount(const String& username, const String& password)
	:username(username), password(password) {}

void CreateAccount::execute() const
{
	if (usersRepository->getCurrentUserConst())
	{
		std::cout << "User is logged. Log out to register as a new user!\n" ;
		return;
	}

	if (!validateInput())
	{
		return;
	}

	RegularUser user(this->username, this->password);

	usersRepository->addUser(user);
	std::cout << "Account created!\n";
}

bool CreateAccount::validateInput() const
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