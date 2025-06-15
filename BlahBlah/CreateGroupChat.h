#pragma once
#include "Command.h"

class CreateGroupChat : public Command
{
private:
    Vector<String> members;
    String groupName;

public:
    CreateGroupChat(const String& groupName, const Vector<String>& members);

    void execute() const override;

    bool validateInput() const override;
};

