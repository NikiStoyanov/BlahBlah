#pragma once
#include <cstdint>

class Utils
{
public:
    static uint32_t getTextLength(const char* text);

    static char* copyText(const char* source);

    static bool compareStrings(const char* first, const char* second);
};
