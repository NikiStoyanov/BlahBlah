// Nikolay Stoyanov 2MI0600435

#pragma once

#include "Chat.h"
#include "Vector.hpp"

class ChatsRepository
{
private:
	static ChatsRepository* instance;

	Vector<Chat*> chats;

	ChatsRepository();

public:
	static ChatsRepository* getInstance();
	static void freeInstance();

	Chat* addChat(const Chat& chat);

	void saveChatsList();
	void saveToTextFiles();
	void loadFromTextFiles();

	Vector<Chat*> getChatsByUsername(const String& username);
	bool isChatAlreadyCreated(const String& firstUsername, const String& secondUsername) const;
	bool isChatAlreadyCreated(const Chat& chat) const;

	~ChatsRepository();
};