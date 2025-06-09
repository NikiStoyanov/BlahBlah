// Nikolay Stoyanov 2MI0600435

#pragma once

#include "UsersRepository.h"

class Command
{
protected:
	UsersRepository* usersRepository;

public:
	Command();
	virtual void execute() const = 0;
	virtual bool validateInput() const = 0;
	virtual ~Command() = default;
};