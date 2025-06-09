// Nikolay Stoyanov 2MI0600435

#pragma once

#include <cstdint>

constexpr uint16_t REALLOCATE_FACTOR = 2;

constexpr uint8_t MAX_COMMAND_LENGTH = 255;
constexpr uint8_t MAX_USERNAME_LENGTH = 32;
constexpr uint8_t MAX_PASSWORD_LENGTH = 32;
constexpr uint8_t MAX_USERS = 100;
constexpr int MAX_TOKENS = 16;

constexpr char USERS_TEXT_FILE_NAME[] = "users.txt";
constexpr char USERS_BINARY_FILE_NAME[] = "users.dat";