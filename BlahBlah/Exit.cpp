// Nikolay Stoyanov 2MI0600435

#include <iostream>

#include "Exit.h"
#include "ChatSystem.h"

void Exit::execute() const
{
	std::cout << "Saving app data... Goodbye!\n";
	ChatSystem::stop();
}

bool Exit::validateInput() const
{
	return true;
}
