// Nikolay Stoyanov 2MI0600435

#pragma once

#include "Chat.h"
#include "String.h"

class User
{
protected:
    String username;
    String password;

    Vector<Chat*> chats;

    User(const User&) = default;
    User& operator=(const User&) = default;

public:
    User(const String& username, const String& password);
    virtual ~User() = default;

    const String& getUsername() const;

    void addChat(Chat* chat);
    Vector<Chat*> getChats() const;
    void assignChats(const Vector<Chat*>& chats);

    bool checkPassword(const String& pass) const;

    virtual bool isAdmin() const = 0;
    virtual User* clone() const = 0;

    virtual void saveToTextFile(std::ostream& os) const = 0;
    virtual void saveToBinaryFile(std::ostream& os) const = 0;

    static User* loadFromTextFile(std::istream& is);
};