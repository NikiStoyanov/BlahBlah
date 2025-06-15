// Nikolay Stoyanov 2MI0600435

#include "ChatSystem.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
int main()
{
	ChatSystem system;

	system.run();
	_CrtDumpMemoryLeaks();
}
