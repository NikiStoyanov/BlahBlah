// Nikolay Stoyanov 2MI0600435

#include "fstream"

#include "UsersRepository.h"

#include <iostream>

#include "AdminUser.h"
#include "ChatsRepository.h"
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

bool UsersRepository::isUsernameTaken(const String& username) const
{
	uint32_t usersCount = this->users.size();

	for (uint32_t i = 0; i < usersCount; i++)
	{
		if (users[i]->getUsername() == username)
		{
			return true;
		}
	}

	return false;
}

void UsersRepository::addUser(const User& user)
{
	users.push_back(user.clone());
}

void UsersRepository::saveToTextFile()
{
	std::ofstream ofs(USERS_TEXT_FILE_NAME);

	if (!ofs.is_open())
	{
		throw std::exception("File could not be opened.");
	}

	ofs << AdminUser::getNextAdminCode() << '\n';

	uint32_t usersCount = users.size();

	for (uint32_t i = 0; i < usersCount; i++)
	{
		users[i]->saveToTextFile(ofs);
	}

	ofs.close();
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

		ChatsRepository* chats = ChatsRepository::getInstance();
		user->assignChats(chats->getChatsByUsername(user->getUsername()));

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

void UsersRepository::assignChatToMembers(Chat* chat)
{
	const Vector<String>& members = chat->getMembers();

	for (uint32_t i = 0; i < members.size(); ++i)
	{
		User* user = this->findByUsername(members[i]);
		if (user)
		{
			user->addChat(chat);
		}
	}
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

UsersRepository::~UsersRepository()
{
	for (uint32_t i = 0; i < users.size(); i++)
	{
		std::cout << "Deleting user: " << users[i]->getUsername() << '\n';
		delete users[i];
	}

	users.clear();
}