// Nikolay Stoyanov 2MI0600435

#pragma once

#include "ChatsRepository.h"
#include "UsersRepository.h"

class Command
{
protected:
	UsersRepository* usersRepository;
	ChatsRepository* chatsRepository;

public:
	Command();
	virtual void execute() const = 0;
	virtual bool validateInput() const = 0;
	virtual ~Command() = default;
};