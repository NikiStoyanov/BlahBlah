#pragma once
#include "Command.h"
class GroupStats : public Command
{
private:
    uint32_t chatId;

public:
    GroupStats(uint32_t id);
    void execute() const override;
    bool validateInput() const override;
};

