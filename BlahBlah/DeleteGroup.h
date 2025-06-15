#pragma once
#include "Command.h"
class DeleteGroup : public Command
{
private:
    uint32_t chatId;

public:
    DeleteGroup(uint32_t id);
    void execute() const override;
    bool validateInput() const override;
};

