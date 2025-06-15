#pragma once

#include "Command.h"

class ViewAllChats : public Command
{
public:
	void execute() const override;

	bool validateInput() const override;
};

