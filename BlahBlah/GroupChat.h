#pragma once
#include "Chat.h"

class GroupChat : public Chat
{
private:
    String groupName;
    String adminUsername;

public:
    GroupChat(uint32_t id, const String& groupName, const String& adminUsername, const Vector<String>& members);

    const String& getGroupName() const;
    const String& getAdminUsername() const;
    void setAdminUsername(const String& username);

    bool isGroup() const override;
    void addMember(const String& username);
    void removeMember(const String& username);
    bool isMember(const String& username) const;

    void saveToTextFile(std::ostream& os) const override;
    static GroupChat* loadFromTextFile(std::istream& is);

    Chat* clone() const override;
    String getDisplayName() const override;
};