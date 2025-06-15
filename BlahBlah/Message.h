// Nikolay Stoyanov 2MI0600435

#pragma once

#include <ctime>

#include "String.h"

class Message
{
private:
    uint32_t id;
    String sender;
    time_t timestamp;
    String content;

public:
    Message(uint32_t id, const String& sender, const String& content);

    uint32_t getId() const;
    const String& getSender() const;
    time_t getTimestamp() const;
    const String& getContent() const;

    // void saveToTextFile(std::ostream& os) const;
    // static Message* loadFromTextFile(std::istream& is);
};
