#include "GroupStats.h"

#include <iostream>

#include "GroupChat.h"

GroupStats::GroupStats(uint32_t chatId)
    : chatId(chatId)
{
}

void GroupStats::execute() const
{
    if (!validateInput()) return;

    GroupChat* group = (GroupChat*)(chatsRepository->getChatById(chatId));

    const Vector<String>& members = group->getMembers();
    const Vector<Message>& messages = group->getMessages();

    Vector<String> senders;
    Vector<size_t> counts;

    for (size_t i = 0; i < messages.size(); i++)
    {
        const String& sender = messages[i].getSender();
        bool found = false;

        for (size_t j = 0; j < senders.size(); j++)
        {
            if (senders[j] == sender)
            {
                counts[j]++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            senders.push_back(sender);
            counts.push_back(1);
        }
    }

    String topUser = "N/A";
    size_t maxMessages = 0;

    for (size_t i = 0; i < senders.size(); i++)
    {
        if (counts[i] > maxMessages)
        {
            maxMessages = counts[i];
            topUser = senders[i];
        }
    }

    std::cout << group->getGroupName()
        << ": " << members.size() << " members, "
        << messages.size() << " msg, "
        << "Top: " << topUser << " (" << maxMessages << " msg)"
        << std::endl;
}

bool GroupStats::validateInput() const
{
    const Chat* chat = chatsRepository->getChatById(chatId);
    if (!chat)
    {
        std::cout << "Chat with ID " << chatId << " not found.\n";
        return false;
    }

    if (!chat->isGroup())
    {
        std::cout << "Chat is not a group chat.\n";
        return false;
    }

    return true;
}