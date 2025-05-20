#pragma once
#include <memory>
#include <string>
#include <unordered_map>

#include "User.h"

class ChatSystem
{
    uint32_t usersCount;
    User* users;

    //Chat* chats;

    User* currentUser;

public:
    static void run();

    void load();
    void save();

    int32_t login(const char* username, const char* password);

    void createAccount(const std::string& username, const std::string& password);

    void createGroup(const std::string& groupName, const std::vector<std::string>& participants);

    void viewChats();
    void selectChat(const std::string& chatID);
    void logout();

    void deleteUser(const std::string& username);
    void deleteGroup(const std::string& chatID);
    void viewAllChats();
};

