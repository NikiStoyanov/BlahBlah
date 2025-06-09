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

	//bool logUser(const String& username, const String& password);

	//User* find(int userId);
	//int find(const char* username) const;
	void setCurrentUser(User* user);
	User* getCurrentUser();
	const User* getCurrentUserConst() const;
	void logout();
	
	//void logOutUser();


// public:
// 	bool login(const std::string& username, const std::string& password);
// 	void logout();
// 	User* getCurrentUser() const;
// 	bool deleteUser(const std::string& username);
// 	const std::map<std::string, std::unique_ptr<User>>& getAllUsers() const;
};