// Nikolay Stoyanov 2MI0600435

#include "User.h"
#include "AdminUser.h"
#include "RegularUser.h"

User::User(const String& username, const String& password)
	: username(username), password(password) {}

bool User::checkPassword(const String& pass) const
{
	return this->password == pass;
}

User* User::loadFromTextFile(std::istream& is)
{
    bool isAdmin;

    if (!(is >> isAdmin)) return nullptr;

    if (isAdmin)
    {
        return AdminUser::loadFromTextFile(is);
    }
    else
    {
        return RegularUser::loadFromTextFile(is);
    }
}

const String& User::getUsername() const
{
	return this->username;
}

void User::addChat(Chat* chat)
{
    this->chats.push_back(chat);
}

void User::assignChats(const Vector<Chat*>& chats)
{
    this->chats = chats;
}

Vector<Chat*> User::getChats() const
{
    return this->chats;
}
