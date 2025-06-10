// Nikolay Stoyanov 2MI0600435

#pragma once

#include "Command.h"
#include "String.h"

class CreateAdmin : public Command
{
private:
    String username;
    String password;

public:
    CreateAdmin(const String& username, const String& password);

    void execute() const override;

    bool validateInput() const override;
};