// Nikolay Stoyanov 2MI0600435

#pragma once

#include <ctime>

#include "String.h"

class Message
{
private:
    String sender;
    time_t timestamp;
    String content;

public:
    Message() = default;
    Message(const String& sender, const String& content);

    const String& getSender() const;
    time_t getTimestamp() const;
    const String& getContent() const;
    String getFormattedTimestamp() const;

    void saveToTextFile(std::ostream& os) const;
    static Message loadFromTextFile(std::istream& is);
};
