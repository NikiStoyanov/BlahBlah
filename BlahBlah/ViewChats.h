#pragma once
#include "Command.h"
class ViewChats : public Command
{
public:
	void execute() const override;

	bool validateInput() const override;
};

