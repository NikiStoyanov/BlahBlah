// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "CreateChat.h"

#include "AdminUser.h"
#include "Chat.h"

CreateChat::CreateChat(const String& username)
	:username(username) {}

void CreateChat::execute() const
{
	if (!usersRepository->getCurrentUserConst())
	{
		std::cout << "You need to be logged in in order to create a chat!\n";
		return;
	}

	if (!validateInput())
	{
		return;
	}

	Chat chat(usersRepository->getCurrentUserConst()->getUsername(), this->username);

	if (chatsRepository->isChatAlreadyCreated(chat))
	{
		std::cout << "Chat with " << this->username << " already exists!\n";
		return;
	}

	Chat::setNextChatId(Chat::getNextChatId() + 1);

	Chat* addedChat = chatsRepository->addChat(chat);

	usersRepository->assignChatToMembers(addedChat);

	std::cout << "Chat with " << this->username << " created!\n";
}

bool CreateChat::validateInput() const
{
	if (this->username.empty())
	{
		std::cout << "Username could not be empty.\n";
		return false;
	}

	if (!usersRepository->isUsernameTaken(this->username))
	{
		std::cout << "There is no user with this username.\n";
		return false;
	}

	if (this->username == usersRepository->getCurrentUserConst()->getUsername())
	{
		std::cout << "You cannot have a chat with yourself.\n";
		return false;
	}

	return true;
}