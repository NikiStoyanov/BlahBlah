#include "RegularUser.h"

RegularUser::RegularUser(const String& name, const String& pass)
	: User(name, pass){}

bool RegularUser::isAdmin() const
{
	return false;
}

User* RegularUser::clone() const
{
	return new RegularUser(*this);
}

void RegularUser::saveToTextFile(std::ostream& os) const
{
	os << isAdmin() << ' ' << username << ' ' << password << '\n';
}

void RegularUser::saveToBinaryFile(std::ostream& os) const
{
}

User* RegularUser::loadFromTextFile(std::istream& is)
{
	String username, password;
	is >> username >> password;

	return new RegularUser(username, password);
}