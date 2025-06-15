#include "Chat.h"

uint32_t Chat::nextChatId = 1;

Chat::Chat(uint32_t id, const Vector<String>& members)
{
	this->id = id;
	this->members = members;
}

Chat::Chat(const String& firstUsername, const String& secondUsername)
{
	this->id = nextChatId;
	this->members.push_back(firstUsername);
	this->members.push_back(secondUsername);
}

uint32_t Chat::getId() const
{
	return this->id;
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

Chat* Chat::clone() const
{
	return new Chat(*this);
}

const Vector<String>& Chat::getMembers() const
{
	return this->members;
}

void Chat::saveToTextFile(std::ostream& ofs) const
{
	ofs << id << '\n';

	uint32_t membersCount = members.size();
	for (uint32_t i = 0; i < membersCount; i++)
	{
		ofs << members[i] << ' ';
	}
	ofs << '\n';
}

Chat* Chat::loadFromTextFile(std::istream& ifs)
{
	uint32_t id;
	ifs >> id;
	ifs.ignore();

	String membersLine;
	getline(ifs, membersLine);

	Chat* chat = new Chat(id, membersLine.split());

	return chat;
}
