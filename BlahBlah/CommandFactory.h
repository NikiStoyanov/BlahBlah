// Nikolay Stoyanov 2MI0600435

#pragma once

#include "Command.h"
#include "String.h"

class CommandFactory
{
private:
	CommandFactory() = default;

	static CommandFactory* instance;

public:
	static CommandFactory* getInstance();
	static void freeInstance();

	Command* readCommand(const String& commandText) const;
};
