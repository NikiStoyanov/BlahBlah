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

bool Utils::compareStrings(const char* first, const char* second)
{
    while (*first != '\0' && *second != '\0') 
    {
        if (*first != *second) 
        {
            return false;
        }

        first++;
        second++;
    }

    return (*first == '\0' && *second == '\0');
}

int Utils::stringSplit(char* input, char delimiter, char* tokens[], int maxTokens)
{
    int tokenCount = 0;
    char* current = input;

    while (*current != '\0' && tokenCount < maxTokens)
    {
        while (*current == delimiter)
        {
            ++current;
        }

        if (*current == '\0')
        {
            break;
        }

        tokens[tokenCount++] = current;

        while (*current != '\0' && *current != delimiter) 
        {
            ++current;
        }

        if (*current == delimiter)
        {
            *current = '\0';
            ++current;
        }
    }

    return tokenCount;
}