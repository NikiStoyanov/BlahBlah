#include "DeleteGroup.h"
#include <iostream>
#include "GroupChat.h"

DeleteGroup::DeleteGroup(uint32_t chatId)
    : chatId(chatId) {}

void DeleteGroup::execute() const
{
    if (!validateInput()) return;

    Chat* chat = chatsRepository->getChatById(chatId);
    GroupChat* group = (GroupChat*)(chat);

    const Vector<String>& members = group->getMembers();

    for (uint32_t i = 0; i < members.size(); i++)
    {
        usersRepository->removeChatFromUser(members[i], chatId);
    }

    chatsRepository->removeChat(chatId);

    std::cout << "Group " << group->getGroupName() << " deleted!\n";
}

bool DeleteGroup::validateInput() const
{
    const User* currentUser = usersRepository->getCurrentUserConst();
    if (!currentUser)
    {
        std::cout << "You must be logged in.\n";
        return false;
    }

    Chat* chat = chatsRepository->getChatById(chatId);
    if (!chat)
    {
        std::cout << "Chat with ID " << chatId << " does not exist.\n";
        return false;
    }

    if (!chat->isGroup())
    {
        std::cout << "This command is only for group chats.\n";
        return false;
    }

    if (!this->usersRepository->getCurrentUserConst()->isAdmin())
    {
        std::cout << "Only the admin can delete the group.\n";
        return false;
    }

    return true;
}