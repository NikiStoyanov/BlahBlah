// Nikolay Stoyanov 2MI0600435

#include "Message.h"

Message::Message(uint32_t id, const String& sender, const String& content)
    : id(id), sender(sender), timestamp(std::time(nullptr)), content(content) {}

uint32_t Message::getId() const
{
    return id;
}

const String& Message::getSender() const
{
    return sender;
}

time_t Message::getTimestamp() const
{
    return timestamp;
}

const String& Message::getContent() const
{
    return content;
}
