#include "Command.h"

// // Nikolay Stoyanov 2MI0600435
//
// #include <iostream>
//
// #include "ChatSystem.h"
//
// #include "Constants.h"
// #include "Utils.h"
//
// void ChatSystem::getHelp()
// {
//
//     std::cout << "create-account <username> <password>" << std::endl;
//     std::cout << "login <username> <password>" << std::endl;
//     std::cout << "quit" << std::endl;
// }
//
// void ChatSystem::readCommand()
// {
//     char input[MAX_COMMAND_LENGTH];
//     char* tokens[MAX_TOKENS];
//
//     std::cin.getline(input, MAX_COMMAND_LENGTH);
//
//     int tokenCount = Utils::stringSplit(input, ' ', tokens, MAX_TOKENS);
//
//     if (tokenCount == 0)
//     {
//         std::cout << "No command entered.\n";
//         return;
//     }
//
//     if (Utils::compareStrings(tokens[0], "create-account"))
//     {
//         if (tokenCount != 3) 
//         {
//             std::cout << "Usage: create-account <username> <password>\n";
//             return;
//         }
//
//         //createAccount(tokens[1], tokens[2]);
//     }
//     else if (Utils::compareStrings(tokens[0], "login"))
//     {
//         if (tokenCount != 3) 
//         {
//             std::cout << "Usage: login <username> <password>\n";
//             return;
//         }
//
//         login(tokens[1], tokens[2]);
//     }
//     else if (strcmp(tokens[0], "logout") == 0) {
//         //logout();
//     }
//     
//     /*else if (strcmp(tokens[0], "create-group") == 0) {
//         if (tokenCount < 3) {
//             std::cout << "Usage: create-group <groupName> <user1> [user2...]\n";
//             return;
//         }
//         const char* groupName = tokens[1];
//         createGroupChat(groupName, &tokens[2], tokenCount - 2);
//     }
//     else if (strcmp(tokens[0], "view-chats") == 0) {
//         viewChats();
//     }
//     else {
//         std::cout << "Unknown command: " << tokens[0] << "\n";
//     }*/
// }
//
// int32_t ChatSystem::login(const char* username, const char* password)
// {
// 	for (uint32_t i = 0; i < usersCount; i++)
// 	{
// 		bool isUsernameMatch = Utils::compareStrings(this->users[i].getUsername(), username);
//
// 		if (isUsernameMatch)
// 		{
// 			bool isPasswordMatch = this->users[i].checkPassword(password);
// 			if (isPasswordMatch)
// 			{
// 				this->currentUser = &this->users[i];
// 				return 1;
// 			}
// 			else
// 			{
// 				return 0;
// 			}
// 		}
// 	}
//
// 	return -1;
// 	std::cout << "Account not found. Create? (y/n)";
// }
