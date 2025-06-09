#pragma once

#include "Command.h"
#include "String.h"

class CommandFactory
{
public:
	static CommandFactory* getInstance();
	static void freeInstance();

	Command* readCommand(const String& commandText) const;

private:
	CommandFactory() = default;

	static CommandFactory* instance;
};
