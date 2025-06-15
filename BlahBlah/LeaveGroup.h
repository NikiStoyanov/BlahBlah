#pragma once
#include "Command.h"
class LeaveGroup : public Command
{
private:
    uint32_t chatId;

public:
    LeaveGroup(uint32_t id);
    void execute() const override;
    bool validateInput() const override;
};