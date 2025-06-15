// Nikolay Stoyanov 2MI0600435

#pragma once
#include <cstdint>

#include "Message.h"
#include "String.h"
#include "Vector.hpp"

class Chat
{
protected:
    static uint32_t nextChatId;
    uint32_t id;

    Vector<Message> messages;
    Vector<String> members;

    
public:
    Chat() = default;
    Chat(uint32_t id, const Vector<String>& members);
    Chat(const String& firstUsername, const String& secondUsername);
    virtual ~Chat() = default;

    virtual bool isGroup() const;
    static uint32_t getNextChatId();
    static void setNextChatId(uint32_t newId);

    uint32_t getId() const;
    const Vector<String>& getMembers() const;
    const Vector<Message>& getMessages() const;

    virtual Chat* clone() const;

    void addMessage(const Message& msg);
    void saveMessagesToTextFile(std::ostream& ofs) const;
    void loadMessagesFromTextFile(std::istream& ifs);

    virtual void saveToTextFile(std::ostream& ofs) const;
    static Chat* loadFromTextFile(std::istream& ifs);

    virtual String getDisplayName() const;
};
