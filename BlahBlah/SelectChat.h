#pragma once

#include "Command.h"

class SelectChat : public Command
{
private:
    uint32_t chatId;

public:
    SelectChat(uint32_t id);
    void execute() const override;
    bool validateInput() const override;
};

