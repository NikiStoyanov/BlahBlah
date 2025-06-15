// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "CommandFactory.h"
#include "CreateAccount.h"
#include "CreateAdmin.h"
#include "CreateChat.h"
#include "Exit.h"
#include "Login.h"
#include "Logout.h"
#include "String.h"
#include "ViewChats.h"

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
	const Vector<String> tokens = line.split();

	if (tokens.size() == 3 && tokens[0] == "create-admin")
	{
		return new CreateAdmin(tokens[1], tokens[2]);
	}
	else if (tokens.size() == 3 && tokens[0] == "create-account")
	{
		return new CreateAccount(tokens[1], tokens[2]);
	}
	else if (tokens.size() == 3 && tokens[0] == "login")
	{
		return new Login(tokens[1], tokens[2]);
	}
	else if (tokens.size() == 1 && tokens[0] == "logout")
	{
		return new Logout();
	}
	else if (tokens.size() == 2 && tokens[0] == "create-chat")
	{
		return new CreateChat(tokens[1]);
	}
	else if (tokens.size() == 1 && tokens[0] == "view-chats")
	{
		return new ViewChats();
	}
	else if (tokens.size() == 1 && tokens[0] == "exit")
	{
		return new Exit();
	}
	else
	{
		return nullptr;
	}
}