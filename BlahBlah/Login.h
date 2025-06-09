// Nikolay Stoyanov 2MI0600435

#pragma once

#include "Command.h"
#include "String.h"

class Login : public Command
{
private:
    String username;
    String password;

public:
    Login(const String& username, const String& password);

    void execute() const override;

    bool validateInput() const override;
};

