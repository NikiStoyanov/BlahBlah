// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "CommandFactory.h"

#include "AddToGroup.h"
#include "CreateAccount.h"
#include "CreateAdmin.h"
#include "CreateChat.h"
#include "CreateGroupChat.h"
#include "DeleteGroup.h"
#include "Exit.h"
#include "GroupStats.h"
#include "KickFromGroup.h"
#include "LeaveGroup.h"
#include "Login.h"
#include "Logout.h"
#include "SelectChat.h"
#include "SetGroupAdmin.h"
#include "String.h"
#include "Utils.h"
#include "ViewAllChats.h"
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
	else if (tokens.size() >= 3 && tokens[0] == "create-group")
	{
		Vector<String> members = tokens;
		members.erase(0, 1);
		return new CreateGroupChat(tokens[1], members);
	}
	else if (tokens.size() == 1 && tokens[0] == "view-chats")
	{
		return new ViewChats();
	}
	else if (tokens.size() == 1 && tokens[0] == "view-all-chats")
	{
		return new ViewAllChats();
	}
	else if (tokens.size() == 2 && tokens[0] == "select-chat")
	{
		return new SelectChat(Utils::atoi(tokens[1]));
	}
	else if (tokens.size() == 2 && tokens[0] == "group-stats")
	{
		return new GroupStats(Utils::atoi(tokens[1]));
	}
	else if (tokens.size() == 2 && tokens[0] == "leave-group")
	{
		return new LeaveGroup(Utils::atoi(tokens[1]));
	}
	else if (tokens.size() == 2 && tokens[0] == "delete-group")
	{
		return new DeleteGroup(Utils::atoi(tokens[1]));
	}
	else if (tokens.size() == 3 && tokens[0] == "add-to-group")
	{
		return new AddToGroup(Utils::atoi(tokens[1]), tokens[2]);
	}
	else if (tokens.size() == 3 && tokens[0] == "set-group-admin")
	{
		return new SetGroupAdmin(Utils::atoi(tokens[1]), tokens[2]);
	}
	else if (tokens.size() == 3 && tokens[0] == "kick-from-group")
	{
		return new KickFromGroup(Utils::atoi(tokens[1]), tokens[2]);
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