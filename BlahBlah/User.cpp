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
