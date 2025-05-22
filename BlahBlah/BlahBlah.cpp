#include <iostream>

#include "ChatSystem.h"
#include "String.h"
#include "Vector.hpp"

int main()
{
	Vector<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);

	for (int i = 0; i < numbers.size(); ++i)
	{
		std::cout << numbers[i];
	}
	ChatSystem system;

	system.run();
}
