// 2-3 Activity - Buffer Overflow Coding.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// // Molly Vaughns
// SNHU - CS-405 Secure Coding - Joseph Kovacic
//

// Define max length for input, based on client requirement
#define MAX_INPUT_LENGTH 20

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_number
	//  variable, and its position in the declaration. It must always be directly before the variable used for input.
	//  You must notify the user if they entered too much data.

	const std::string account_number = "CharlieBrown42";
	// Prevent buffer overflow by using a string over a character array
	char user_input[MAX_INPUT_LENGTH];
	// Get array length
	std::size_t len = sizeof(user_input);
	std::cout << "Enter a value: ";
	// Read user input, set max input to 20 chars
	std::cin.getline(user_input, MAX_INPUT_LENGTH);

	// Check if input over 20 chars
	// True = display warning of buffer overflow and trimmed input
	// Clear buffer and input errors
	if (!std::cin)
	{
		std::cout << "Buffer Overflow! Input exceeding buffer limit of 20 will be stripped." << std::endl << std::endl;
		// Clear cin errors
		std::cin.clear();
		// Clear anything still in buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "You entered: " << user_input << std::endl;
	std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
