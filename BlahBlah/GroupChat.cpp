#include "GroupChat.h"
#include <sstream>
#include <ctime>

GroupChat::GroupChat(uint32_t id, const String& groupName, const String& adminUsername, const Vector<String>& members)
    : Chat(id, members), groupName(groupName), adminUsername(adminUsername) {}

const String& GroupChat::getGroupName() const
{
    return groupName;
}

const String& GroupChat::getAdminUsername() const
{
    return adminUsername;
}

void GroupChat::setAdminUsername(const String& username)
{
    adminUsername = username;
}

bool GroupChat::isGroup() const
{
    return true;
}

bool GroupChat::isMember(const String& username) const
{
    for (size_t i = 0; i < members.size(); i++) 
    {
        if (members[i] == username) 
        {
            return true;
        }
    }
    return false;
}

void GroupChat::addMember(const String& username)
{
    if (!isMember(username)) 
    {
        members.push_back(username);
    }
}

void GroupChat::removeMember(const String& username)
{
    for (uint32_t i = 0; i < members.size(); i++) 
    {
        if (members[i] == username) 
        {
            members.erase(i);
            break;
        }
    }
}

void GroupChat::saveToTextFile(std::ostream& os) const
{
    os << "GROUP" << '\n';
    os << id << '\n';
    os << groupName << '\n';
    os << adminUsername << '\n';

    for (uint32_t i = 0; i < members.size(); i++) 
    {
        os << members[i] << ' ';
    }
    os << '\n';
    
    saveMessagesToTextFile(os);
}

GroupChat* GroupChat::loadFromTextFile(std::istream& is)
{
    uint32_t id;
    String groupName;
    String adminUsername;

    is >> id;
    is.ignore();

    getline(is, groupName);
    getline(is, adminUsername);

    String membersLine;
    getline(is, membersLine);
    Vector<String> members = membersLine.split();

    GroupChat* chat = new GroupChat(id, groupName, adminUsername, members);

    chat->loadMessagesFromTextFile(is);

    return chat;
}

Chat* GroupChat::clone() const
{
    return new GroupChat(*this);
}

String GroupChat::getDisplayName() const
{
    return groupName;
}