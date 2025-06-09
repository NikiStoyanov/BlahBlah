#include "Utils.h"

uint32_t Utils::getTextLength(const char* text)
{
    uint32_t length = 0;
    while (text[length] != '\0')
    {
        length++;
    }

    return length;
}

char* Utils::copyText(const char* source)
{
    uint32_t sourceLength = getTextLength(source);

    char* destination = new char[sourceLength + 1];

    for (uint32_t i = 0; i < sourceLength; i++)
    {
        destination[i] = source[i];
    }

    destination[sourceLength] = '\0';

    return destination;
}