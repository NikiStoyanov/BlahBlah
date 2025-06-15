// Nikolay Stoyanov 2MI0600435

#include "Command.h"

Command::Command()
{
	usersRepository = UsersRepository::getInstance();
	chatsRepository = ChatsRepository::getInstance();
}