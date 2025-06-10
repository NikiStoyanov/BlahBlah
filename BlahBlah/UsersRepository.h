// Nikolay Stoyanov 2MI0600435

#pragma once

#include "User.h"
#include "Vector.hpp"

class UsersRepository
{
private:
	static UsersRepository* instance;

	Vector<User*> users;
	User* currentUser = nullptr;

	UsersRepository();

public:
	static UsersRepository* getInstance();
	static void freeInstance();


	bool isUsernameFree(const String& username);
	void addUser(const User& user);
	void saveToTextFile();
	void loadFromTextFile();

	User* findByUsername(const String& username);
	const User* findByUsername(const String& username) const;

	void setCurrentUser(User* user);
	User* getCurrentUser();
	const User* getCurrentUserConst() const;
	void logout();
};