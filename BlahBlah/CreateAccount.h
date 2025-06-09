#pragma once

#include "Command.h"
#include "String.h"

class CreateAccount : public Command
{
    String username;
    String password;

public:
    CreateAccount(const String& username, const String& password);

    void execute() const override;

    bool validateInput() const override;
};