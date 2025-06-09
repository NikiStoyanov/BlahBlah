#include "CommandFactory.h"

#include <iostream>

#include "CreateAccount.h"
#include "String.h"

CommandFactory* CommandFactory::instance = nullptr;

CommandFactory* CommandFactory::getInstance()
{
	if (!instance)
	{
		instance = new CommandFactory();
	}

	return instance;
}

void CommandFactory::freeInstance()
{
	delete instance;
}

Command* CommandFactory::readCommand(const String& line) const
{
	Vector<String> tokens = line.split();

	if (tokens[0] == "create-account" && tokens.size() == 3)
	{
		return new CreateAccount(tokens[1], tokens[2]);
	}
	else if (tokens[0] == "exit" && tokens.size() == 1)
	{

	}
	else
	{
		return nullptr;
	}
}