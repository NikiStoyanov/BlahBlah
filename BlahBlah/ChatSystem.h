// Nikolay Stoyanov 2MI0600435

#pragma once

class ChatSystem
{
private:
	static bool isRunning;

public:
	static void stop();
	static bool running();

	void run();
};

