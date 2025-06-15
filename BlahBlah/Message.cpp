// Nikolay Stoyanov 2MI0600435

#include "Message.h"
#include <ctime>
#include <sstream>

Message::Message(const String& sender, const String& content)
    : sender(sender), timestamp(std::time(nullptr)), content(content) {}

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


String Message::getFormattedTimestamp() const
{
    std::tm timeInfo;
    localtime_s(&timeInfo, &timestamp);

    std::stringstream ss;
    if (timeInfo.tm_mday < 10) ss << "0";
    ss << timeInfo.tm_mday << "/";

    if (timeInfo.tm_mon + 1 < 10) ss << "0";
    ss << (timeInfo.tm_mon + 1) << "/";

    ss << (timeInfo.tm_year + 1900) << " ";

    if (timeInfo.tm_hour < 10) ss << "0";
    ss << timeInfo.tm_hour << ":";

    if (timeInfo.tm_min < 10) ss << "0";
    ss << timeInfo.tm_min;

    return String(ss.str().c_str());
}

void Message::saveToTextFile(std::ostream& os) const
{
    os << sender << '\n' << content << '\n' << timestamp << '\n';
}

Message Message::loadFromTextFile(std::istream& is)
{
    String sender, content;
    time_t timestamp;

    is >> sender;
    is.ignore();
    getline(is, content);
    is >> timestamp;

    char ch;
    while (is.get(ch) && ch != '\n') {}

    Message msg(sender, content);
    msg.timestamp = timestamp;
    return msg;
}


