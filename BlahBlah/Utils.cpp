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
