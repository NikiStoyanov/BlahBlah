#include "User.h"
#include "Utils.h"

User::User(const char* username, const char* password)
{
	this->username = Utils::copyText(username);
	this->password = Utils::copyText(password);
}

User::~User()
{
	delete[] this->username;
	delete[] this->password;
}

bool User::checkPassword(const char* password) const
{
	return Utils::compareStrings(this->password, password);
}

const char* const User::getUsername() const
{
	return this->username;
}
