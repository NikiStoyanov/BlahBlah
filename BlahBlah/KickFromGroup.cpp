#include "KickFromGroup.h"

#include <iostream>

#include "GroupChat.h"

KickFromGroup::KickFromGroup(uint32_t id, const String& username)
    : chatId(id), username(username)
{
}

void KickFromGroup::execute() const
{
    if (!validateInput()) return;

    GroupChat* group = (GroupChat*)(chatsRepository->getChatById(this->chatId));
    group->removeMember(username);

    std::cout << username << " was removed from the group.\n";
}

bool KickFromGroup::validateInput() const
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

    if (group->getAdminUsername() != currentUser->getUsername())
    {
        std::cout << "Only the group admin can kick members.\n";
        return false;
    }

    if (username == group->getAdminUsername())
    {
        std::cout << "The admin cannot remove themselves from the group.\n";
        return false;
    }

    if (!group->isMember(username))
    {
        std::cout << username << " is not a member of the group.\n";
        return false;
    }

    if (!usersRepository->isUsernameTaken(username))
    {
        std::cout << "User '" << username << "' does not exist.\n";
        return false;
    }

    return true;
}
