// Nikolay Stoyanov 2MI0600435

#include "AdminUser.h"

uint32_t AdminUser::nextAdminCode = 1;

AdminUser::AdminUser(const String& name, const String& pass, uint32_t adminCode)
	: User(name, pass)
{
	this->adminCode = adminCode;

	AdminUser::nextAdminCode++;
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

User* AdminUser::loadFromTextFile(std::istream& is)
{
	String username, password;
	uint32_t adminCode;
	is >> username >> password >> adminCode;

	return new AdminUser(username, password, adminCode);
}

uint32_t AdminUser::getNextAdminCode()
{
	return nextAdminCode;
}

void AdminUser::setNextAdminCode(uint32_t newCode)
{
	if (newCode >= nextAdminCode) 
	{
		nextAdminCode = newCode;
	}
}