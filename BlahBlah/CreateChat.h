// Nikolay Stoyanov 2MI0600435

#pragma once

#include "Command.h"

class CreateChat : public Command
{
private:
    String username;

public:
    CreateChat(const String& username);

    void execute() const override;

    bool validateInput() const override;
};

