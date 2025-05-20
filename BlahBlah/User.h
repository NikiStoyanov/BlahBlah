#pragma once
#include <string>

class User
{
protected:
    char* username;
    char* password;
    // std::vector<std::pair<std::string, std::vector<Message>>> chats;

public:
    User(const char* username, const char* password);
    User(const User&) = delete;
    User& operator=(const User&) = delete;

    virtual ~User();

    bool checkPassword(const char* password) const;
    // virtual void viewChats() const;
    // virtual void sendMessage(const std::string& receiver, const std::string& text);
    // virtual void logout();
    //
    const char* const getUsername() const;
};

