#include "SetGroupAdmin.h"

#include <iostream>

#include "GroupChat.h"

SetGroupAdmin::SetGroupAdmin(uint32_t id, const String& username)
	: chatId(id), username(username) {}

void SetGroupAdmin::execute() const
{
    if (!validateInput()) return;

    GroupChat* group = (GroupChat*)(chatsRepository->getChatById(this->chatId));
    group->setAdminUsername(username);

    std::cout << username << " is now the group admin.\n";
}

bool SetGroupAdmin::validateInput() const
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
        std::cout << "This command is only available for group chats.\n";
        return false;
    }

    GroupChat* group = (GroupChat*)(currentChat);

    if (group->getAdminUsername() != currentUser->getUsername())
    {
        std::cout << "Only the group admin can change the administrator.\n";
        return false;
    }

    if (!group->isMember(username))
    {
        std::cout << "The new admin must be a member of the group.\n";
        return false;
    }

    return true;
}
