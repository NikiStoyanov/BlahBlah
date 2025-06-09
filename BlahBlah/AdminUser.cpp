// Nikolay Stoyanov 2MI0600435

#include "AdminUser.h"

AdminUser::AdminUser(const String& name, const String& pass, const String& adminCode)
	: User(name, pass)
{
	this->adminCode = adminCode;
}

bool AdminUser::isAdmin() const
{
	return true;
}

User* AdminUser::clone() const
{
	return new AdminUser(*this);
}

void AdminUser::saveToTextFile(std::ostream& os) const
{
	os << isAdmin() << ' ' << username << ' ' << password << ' ' << adminCode << '\n';
}

void AdminUser::saveToBinaryFile(std::ostream& os) const
{
}

User* AdminUser::loadFromTextFile(std::istream& is)
{
	String username, password, adminCode;
	is >> username >> password >> adminCode;

	return new AdminUser(username, password, adminCode);
}