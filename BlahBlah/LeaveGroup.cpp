#include "LeaveGroup.h"

// Nikolay Stoyanov 2MI0600435

#include "SelectChat.h"

#include <iostream>
#include <string>

#include "GroupChat.h"

LeaveGroup::LeaveGroup(uint32_t id)
    : chatId(id)
{
}

void LeaveGroup::execute() const
{
    const User* currentUser = usersRepository->getCurrentUserConst();

    if (!currentUser)
    {
        std::cout << "You need to be logged in.\n";
        return;
    }

    Chat* chat = chatsRepository->getChatById(chatId);
    if (!chat)
    {
        std::cout << "Chat with ID " << chatId << " not found.\n";
        return;
    }

    if (!chat->isGroup())
    {
        std::cout << "This is not a group chat.\n";
        return;
    }

    GroupChat* group = (GroupChat*)(chat);
    String username = currentUser->getUsername();

    if (!group->isMember(username))
    {
        std::cout << "You are not a member of this group.\n";
        return;
    }

    if (group->getAdminUsername() == username)
    {
        std::cout << "You are the group admin. Transfer admin rights before leaving.\n";
        return;
    }

    group->removeMember(username);
    usersRepository->removeChatFromUser(currentUser->getUsername(), group->getId());

    std::cout << "You left the group successfully.\n";
}

bool LeaveGroup::validateInput() const
{
    return this->chatId > 0;
}
