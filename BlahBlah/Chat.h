// Nikolay Stoyanov 2MI0600435

#pragma once
#include <cstdint>

#include "Message.h"
#include "String.h"
#include "Vector.hpp"

class Chat
{
private:
    static uint32_t nextChatId;
    uint32_t id;

    Vector<Message> messages;
    Vector<String> members;

    Chat(uint32_t id, const Vector<String>& members);

public:
    Chat(const String& firstUsername, const String& secondUsername);
    static uint32_t getNextChatId();
    static void setNextChatId(uint32_t newId);

    Chat* clone() const;

    void addMessage(const Message& msg);
    const Vector<Message>& getMessages() const;

    uint32_t getId() const;
    const Vector<String>& getMembers() const;

    void saveToTextFile(std::ostream& ofs) const;
    static Chat* loadFromTextFile(std::istream& ifs);
};
