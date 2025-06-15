#include "CreateGroupChat.h"

#include <iostream>

#include "GroupChat.h"

CreateGroupChat::CreateGroupChat(const String& groupName, const Vector<String>& members)
	: members(members), groupName(groupName)
{
}

void CreateGroupChat::execute() const
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


	Vector<String> groupMembers = members;
	groupMembers.push_back(this->usersRepository->getCurrentUserConst()->getUsername());

	GroupChat group(
		Chat::getNextChatId(), 
		this->groupName, 
		this->usersRepository->getCurrentUserConst()->getUsername(), 
		groupMembers
	);

	Chat::setNextChatId(Chat::getNextChatId() + 1);

	Chat* addedGroup = chatsRepository->addChat(group);

	usersRepository->assignChatToMembers(addedGroup);

	std::cout << "Group " << this->groupName << " created with ID " << group.getId() << "!\n";
}

bool CreateGroupChat::validateInput() const
{
	if (this->groupName.empty())
	{
		std::cout << "Group name could not be empty.\n";
		return false;
	}

	if (this->members.empty())
	{
		std::cout << "Cannot create a group with no members.\n";
		return false;
	}

	uint32_t membersCount = members.size();

	for (uint32_t i = 0; i < membersCount; i++)
	{
		if (!usersRepository->isUsernameTaken(this->members[i]))
		{
			std::cout << "There is no user with one of these usernames.\n";
			return false;
		}
	}

	if (this->members.contains(usersRepository->getCurrentUserConst()->getUsername()))
	{
		std::cout << "You cannot have a chat with yourself.\n";
		return false;
	}

	return true;
}
