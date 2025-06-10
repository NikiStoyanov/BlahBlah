// Nikolay Stoyanov 2MI0600435

#pragma once

#include "Command.h"

class Logout : public Command
{
public:
	void execute() const override;

	bool validateInput() const override;
};

