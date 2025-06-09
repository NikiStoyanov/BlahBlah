#pragma once
#include "UsersRepository.h"

class Command
{
public:
	Command();
	virtual void execute() const = 0;
	virtual bool validateInput() const = 0;
	virtual ~Command() = default;

protected:
	UsersRepository* usersRepository;
};

