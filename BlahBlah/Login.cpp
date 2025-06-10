// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "Login.h"
#include "CreateAccount.h"
#include "RegularUser.h"

void Login::listenForUserCreation() const
{
	std::cout << "Account not found. Create? (y/n): ";

	String input;

	getline(std::cin, input);

	if (!input.empty() && (input[0] == 'y' || input[0] == 'Y'))
	{
		CreateAccount command(this->username, this->password);
		command.execute();
		return;
	}

	std::cout << "Login was not successful!\n";
}

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
		listenForUserCreation();
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