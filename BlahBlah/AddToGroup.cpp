#include "AddToGroup.h"

#include <iostream>

#include "GroupChat.h"

AddToGroup::AddToGroup(uint32_t id, const String& username)
	: chatId(id), username(username)
{
}

void AddToGroup::execute() const
{
    if (!validateInput()) return;

    GroupChat* group = (GroupChat*)(chatsRepository->getChatById(this->chatId));
    group->addMember(username);

    std::cout << username << " was added to the group.\n";
}

bool AddToGroup::validateInput() const
{
    const User* currentUser = usersRepository->getCurrentUserConst();
    if (!currentUser)
    {
        std::cout << "You must be logged in to perform this action.\n";
        return false;
    }

    Chat* currentChat = chatsRepository->getChatById(this->chatId);
    if (!currentChat)
    {
        std::cout << "No chat selected.\n";
        return false;
    }

    if (!currentChat->isGroup())
    {
        std::cout << "This command is only valid for group chats.\n";
        return false;
    }

    GroupChat* group = (GroupChat*)(currentChat);

    if (!group->getMembers().contains(currentUser->getUsername()))
    {
        std::cout << "Only group members can add members.\n";
        return false;
    }

    if (group->isMember(username))
    {
        std::cout << username << " is already a member of the group.\n";
        return false;
    }

    if (!usersRepository->isUsernameTaken(username))
    {
        std::cout << "User '" << username << "' does not exist.\n";
        return false;
    }

    return true;
}
