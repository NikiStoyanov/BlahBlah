#pragma once
#include "Command.h"
class AddToGroup : public Command
{
private:
    uint32_t chatId;
    String username;

public:
    AddToGroup(uint32_t id, const String& username);
    void execute() const override;
    bool validateInput() const override;
};

