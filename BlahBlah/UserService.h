#pragma once
#include <map>
#include <memory>
#include <string>

#include "User.h"

class UserService
{
private:
    User** users;
    User* currentUser = nullptr;

public:
    bool createAccount(const std::string& username, const std::string& password, bool isAdmin = false);
    bool login(const std::string& username, const std::string& password);
    void logout();
    User* getCurrentUser() const;
    bool deleteUser(const std::string& username);
    const std::map<std::string, std::unique_ptr<User>>& getAllUsers() const;
};

