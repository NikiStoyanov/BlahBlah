#pragma once

#include "Command.h"
#include "String.h"

class LogInUser : public Command
{
    String username;
    String password;

public:
    LogInUser(const String& username, const String& password);

    void execute() const override;

    bool validateInput() const override;
};

