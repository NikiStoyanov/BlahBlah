#pragma once
#include "Command.h"
class SetGroupAdmin : public Command
{
private:
    uint32_t chatId;
    String username;

public:
    SetGroupAdmin(uint32_t id, const String& username);
    void execute() const override;
    bool validateInput() const override;
};

