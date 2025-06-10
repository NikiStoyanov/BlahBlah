// Nikolay Stoyanov 2MI0600435

#include "fstream"

#include "UsersRepository.h"

#include "AdminUser.h"
#include "RegularUser.h"
#include "Constants.h"

UsersRepository::UsersRepository()
	: currentUser(nullptr) {}

UsersRepository* UsersRepository::instance = nullptr;

UsersRepository* UsersRepository::getInstance()
{
	if (!instance)
	{
		instance = new UsersRepository();
	}

	return instance;
}

void UsersRepository::freeInstance()
{
	delete instance;
	instance = nullptr;
}

bool UsersRepository::isUsernameFree(const String& username)
{
	uint32_t usersCount = this->users.size();

	bool isUsernameFree = true;

	for (uint32_t i = 0; i < usersCount; i++)
	{
		if (users[i]->getUsername() == username)
		{
			isUsernameFree = false;
		}
	}

	return isUsernameFree;
}

void UsersRepository::addUser(const User& user)
{
	users.push_back(user.clone());
}

void UsersRepository::saveToTextFile()
{
	std::ofstream os(USERS_TEXT_FILE_NAME);

	if (!os.is_open())
	{
		throw std::exception("File could not be opened.");
	}

	os << AdminUser::getNextAdminCode() << '\n';

	uint32_t usersCount = users.size();

	for (uint32_t i = 0; i < usersCount; i++)
	{
		users[i]->saveToTextFile(os);
	}

	os.close();
}

void UsersRepository::loadFromTextFile()
{
	std::ifstream is(USERS_TEXT_FILE_NAME);

	if (!is.is_open())
	{
		return;
	}

	uint32_t nextAdminCode;
	is >> nextAdminCode;
	AdminUser::setNextAdminCode(nextAdminCode);

	while (true)
	{
		User* user = User::loadFromTextFile(is);

		if (!user)
		{
			break;
		}

		users.push_back(user);
	}

	is.close();
}

User* UsersRepository::findByUsername(const String& username)
{
	uint32_t usersCount = users.size();

	for (uint32_t i = 0; i < usersCount; i++)
	{
		if (users[i]->getUsername() == username)
		{
			return users[i];
		}
	}

	return nullptr;
}

const User* UsersRepository::findByUsername(const String& username) const
{
	uint32_t usersCount = users.size();

	for (uint32_t i = 0; i < usersCount; i++)
	{
		if (users[i]->getUsername() == username)
		{
			return users[i];
		}
	}

	return nullptr;
}

void UsersRepository::setCurrentUser(User* user)
{
	currentUser = user;
}

User* UsersRepository::getCurrentUser()
{
	return currentUser;
}

const User* UsersRepository::getCurrentUserConst() const
{
	return currentUser;
}

void UsersRepository::logout()
{
	currentUser = nullptr;
}

//
// User* UsersRepository::find(int userId)
// {
// 	if (userId < 0)
// 	{
// 		return nullptr;
// 	}
//
// 	unsigned usersCount = users.size();
//
// 	for (size_t i = 0; i < usersCount; i++)
// 	{
// 		if (users[i].getId() == userId)
// 		{
// 			return &users[i];
// 		}
// 	}
//
// 	return nullptr;
// }
//
//
//
// LoginResult UsersRepository::logUser(const char* username, const char* password)
// {
// 	int userIndex = find(username);
//
// 	if (userIndex < 0)
// 	{
// 		return LoginResult::UsernameNotFound;
// 	}
//
// 	if (users[userIndex].matchPassword(password))
// 	{
// 		loggedUserIndex = userIndex;
// 		return LoginResult::Success;
// 	}
//
// 	return LoginResult::WrongPassword;
// }
//
// int UsersRepository::find(const char* username) const
// {
// 	unsigned usersCount = users.size();
//
// 	for (size_t index = 0; index < usersCount; index++)
// 	{
// 		if (!strcmp(users[index].getUsername().c_str(), username))
// 		{
// 			return index;
// 		}
// 	}
//
// 	return -1;
// }
//
// void UsersRepository::logOutUser()
// {
// 	loggedUserIndex = -1;
// }