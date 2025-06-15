#include "Chat.h"

#include "GroupChat.h"

uint32_t Chat::nextChatId = 1;

Chat::Chat(uint32_t id, const Vector<String>& members)
	: id(id), members(members) {}

Chat::Chat(const String& firstUsername, const String& secondUsername)
{
	this->id = nextChatId;
	this->members.push_back(firstUsername);
	this->members.push_back(secondUsername);
}

bool Chat::isGroup() const
{
	return false;
}

uint32_t Chat::getNextChatId()
{
	return nextChatId;
}

void Chat::setNextChatId(uint32_t newId)
{
	if (newId >= nextChatId)
	{
		nextChatId = newId;
	}
}

uint32_t Chat::getId() const
{
	return this->id;
}

const Vector<String>& Chat::getMembers() const
{
	return this->members;
}

const Vector<Message>& Chat::getMessages() const
{
	return this->messages;
}

Chat* Chat::clone() const
{
	return new Chat(*this);
}

void Chat::addMessage(const Message& msg)
{
	this->messages.push_back(msg);
}

void Chat::saveMessagesToTextFile(std::ostream& ofs) const
{
	ofs << messages.size() << '\n';
	for (uint32_t i = 0; i < messages.size(); i++)
	{
		messages[i].saveToTextFile(ofs);
	}
}

void Chat::loadMessagesFromTextFile(std::istream& ifs)
{
	uint32_t count;
	ifs >> count;
	ifs.ignore();

	for (uint32_t i = 0; i < count; ++i) 
	{
		Message msg = Message::loadFromTextFile(ifs);

		if (!msg.getSender().empty()) 
		{
			messages.push_back(msg);
		}
	}
}

void Chat::saveToTextFile(std::ostream& ofs) const
{
	ofs << "INDIVIDUAL\n";
	ofs << id << '\n';

	uint32_t membersCount = members.size();
	for (uint32_t i = 0; i < membersCount; i++)
	{
		ofs << members[i] << ' ';
	}
	ofs << '\n';

	saveMessagesToTextFile(ofs);
}

Chat* Chat::loadFromTextFile(std::istream& ifs)
{
	String type;
	getline(ifs, type);

	if (type == "GROUP") 
	{
		return GroupChat::loadFromTextFile(ifs);
	}
	else if (type == "INDIVIDUAL") 
	{
		uint32_t id;
		ifs >> id;
		ifs.ignore();

		String membersLine;
		getline(ifs, membersLine);

		Chat* chat = new Chat(id, membersLine.split());
		chat->loadMessagesFromTextFile(ifs);
		return chat;
	}

	return nullptr;
}

String Chat::getDisplayName() const
{
	const Vector<String>& members = getMembers();
	String result;

	for (size_t i = 0; i < members.size(); ++i) 
	{
		result += members[i];
		if (i != members.size() - 1) 
		{
			result += "-";
		}
	}
	return result;
}