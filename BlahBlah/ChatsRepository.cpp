
#include <fstream>

#include "ChatsRepository.h"

#include <iostream>

#include "UsersRepository.h"
#include "Utils.h"

ChatsRepository::ChatsRepository() = default;

ChatsRepository* ChatsRepository::instance = nullptr;

ChatsRepository* ChatsRepository::getInstance()
{
	if (!instance)
	{
		instance = new ChatsRepository();
	}

	return instance;
}

void ChatsRepository::freeInstance()
{
	delete instance;
	instance = nullptr;
}

Chat* ChatsRepository::addChat(const Chat& chat)
{
	Chat* cloned = chat.clone();
	chats.push_back(cloned);
	return cloned;
}

void ChatsRepository::saveChatsList()
{
	std::ofstream ofs(CHATS_LIST_TEXT_FILE_NAME);

	if (!ofs.is_open())
	{
		throw std::exception("File could not be opened.");
	}

	ofs << Chat::getNextChatId() << '\n';

	uint32_t chatsCount = chats.size();

	for (uint32_t i = 0; i < chatsCount; i++)
	{
		ofs << chats[i]->getId() << '\n';
	}

	ofs.close();
}

void ChatsRepository::saveToTextFiles()
{
	this->saveChatsList();

	uint32_t chatsCount = chats.size();

	for (uint32_t i = 0; i < chatsCount; i++)
	{
		Chat* chat = chats[i];
		String filename = "chat_" + Utils::itoa(chat->getId()) + ".txt";

		std::ofstream ofs(filename.c_str());
		
		if (!ofs.is_open())
		{
			throw std::exception("File could not be opened.");
		}

		chat->saveToTextFile(ofs);

		ofs.close();
	}
}

void ChatsRepository::loadFromTextFiles()
{
	std::ifstream ifs(CHATS_LIST_TEXT_FILE_NAME);

	if (!ifs.is_open())
	{
		return;
	}

	uint32_t nextChatId;
	ifs >> nextChatId;
	Chat::setNextChatId(nextChatId);

	uint32_t id;
	while (ifs >> id)
	{
		String path = "chat_" + Utils::itoa(id) + ".txt";
		std::ifstream chatFile(path.c_str());

		if (chatFile.is_open())
		{
			Chat* chat = Chat::loadFromTextFile(chatFile);
			if (chat)
			{
				chats.push_back(chat);
			}
		}
	}

	ifs.close();
}

Vector<Chat*> ChatsRepository::getChatsByUsername(const String& username)
{
	Vector<Chat*> filtered;

	uint32_t chatsCount = chats.size();

	for (uint32_t i = 0; i < chatsCount; i++)
	{
		if (chats[i]->getMembers().contains(username))
		{
			filtered.push_back(chats[i]);
		}
	}

	return filtered;
}

bool ChatsRepository::isChatAlreadyCreated(const String& firstUsername, const String& secondUsername) const
{
	uint32_t chatsCount = chats.size();

	for (uint32_t i = 0; i < chatsCount; i++)
	{
		Chat* chat = chats[i];

		if (chat->getMembers().size() == 2 
			&& chat->getMembers().contains(firstUsername) 
			&& chat->getMembers().contains(secondUsername))
		{
			return true;
		}
	}

	return false;
}

bool ChatsRepository::isChatAlreadyCreated(const Chat& chat) const
{
	uint32_t chatsCount = chats.size();
    const Vector<String>& targetMembers = chat.getMembers();

    for (uint32_t i = 0; i < chatsCount; i++)
    {
        const Vector<String>& currentMembers = chats[i]->getMembers();

        if (currentMembers.size() != targetMembers.size())
        {
			continue;
        }

        bool allMatch = true;

        for (uint32_t j = 0; j < targetMembers.size(); j++)
        {
            if (!currentMembers.contains(targetMembers[j]))
            {
                allMatch = false;
                break;
            }
        }

        if (allMatch)
        {
			return true;
        }
    }

    return false;
}

ChatsRepository::~ChatsRepository()
{
	for (uint32_t i = 0; i < chats.size(); i++)
	{
		delete chats[i];
	}

	chats.clear();
}
