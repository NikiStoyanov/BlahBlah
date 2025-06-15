#include "Utils.h"

String Utils::itoa(uint32_t value)
{
	if (value == 0)
	{
		return String("0");
	}

	String result;

	while (value != 0)
	{
		char digit = '0' + (value % 10);
		result += digit;
		value /= 10;
	}

	result.reverse();

	return result;
}

uint32_t Utils::atoi(String value)
{
	uint32_t length = value.size();

	uint32_t number = 0;

	for (int i = 0; i < length; i++)
	{
		number *= 10;

		number += (value[i] - '0');
	}

	return number;
}
