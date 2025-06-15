// Nikolay Stoyanov 2MI0600435

#include "SelectChat.h"

#include <iostream>
#include <string>

SelectChat::SelectChat(uint32_t id)
	: chatId(id)
{
}

void SelectChat::execute() const
{
    const User* currentUser = usersRepository->getCurrentUserConst();

    if (!currentUser)
    {
        std::cout << "You must be logged in to select a chat.\n";
        return;
    }

    Chat* chat = chatsRepository->getChatById(this->chatId);

    if (!chat) 
    {
        std::cout << "Chat not found.\n";
        return;
    }

    if (!chat->getMembers().contains(currentUser->getUsername())) 
    {
        std::cout << "You are not a member of this chat.\n";
        return;
    }

    std::cout << "Chat " << chatId << ":\n";

    const Vector<Message>& messages = chat->getMessages();

    for (uint32_t i = 0; i < messages.size(); i++)
    {
        std::cout << "[" << messages[i].getSender() << ", "
            << messages[i].getFormattedTimestamp() << "] "
            << messages[i].getContent() << "\n";
    }

    std::cout << "Enter your message (or just press ENTER to skip): ";
    String input;
    getline(std::cin, input);

    if (!input.empty()) 
    {
        Message msg(currentUser->getUsername(), input);
        chat->addMessage(msg);
        std::cout << "Message sent!\n";
    }
}

bool SelectChat::validateInput() const
{
	return true;
}
