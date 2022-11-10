#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <time.h>

// Header imports
#include "Account.hpp"

// Std specific imports
using std::cout;
using std::cin;
using std::string;

// Function definitions
int GetStringLen(string string_to_read);
void StartUpBitTerminal(); // Prints ascii text for start-up
void Clear(); // Clears terminal based on operating system
void Register(string username, string password);
int GenerateRandomAsciiAlphabet();
string GenerateRandomId(int length);

int main() 
{
	StartUpBitTerminal();
	Register("Vankata", "12345");
}

int GetStringLen(string string_to_read)
{
	int i = 0;
	while (string_to_read[i] != '\0')
	{
		i++;
	}
	return i;
}

void StartUpBitTerminal()
{
	string bit_terminal_art = R"(



			  _     _ _        _                      _             _
			 | |__ (_) |_     | |_ ___ _ __ _ __ ___ (_)_ __   __ _| |
			 | '_ \| | __|____| __/ _ \ '__| '_ ` _ \| | '_ \ / _` | |
			 | |_) | | ||_____| ||  __/ |  | | | | | | | | | | (_| | |
			 |_.__/|_|\__|     \__\___|_|  |_| |_| |_|_|_| |_|\__,_|_|




	)";

	for (int i = 0; i < GetStringLen(bit_terminal_art); i++)
	{
		cout << bit_terminal_art[i];
		std::this_thread::sleep_for(std::chrono::microseconds(2));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	Clear();
}


void Register(string username, string password) 
{
	string account_id(GenerateRandomId(10));
	std::ofstream account_file;
	account_file.open("accounts.txt");
	account_file << "ACCOUNT_ID:" << account_id << ", ";
	account_file << "ACCOUNT_USERNAME:" << username << ", ";
	account_file << "ACCOUNT_PASSWORD:" << password << '\n';
	account_file.close();
}

bool Login(string username, string password) {
	string line;
	std::ifstream account_file ("account.txt");
	if (account_file.is_open())
	{
		while (getline(account_file, line))
		{
			if 

			cout << line << '\n';
		}
		myfile.close();
	}
}

bool CheckCredentials(string username, string password)
{
	bool username_valid, password_valid;
	string username_temp, password_temp;
	for (int i = 0; i < GetStringLen(username); i++)
	{
		if ()
	}
}


void Clear()
{
	#if defined _WIN32
	system("cls");
	//clrscr(); // including header file : conio.h
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
	#elif defined (__APPLE__)
	system("clear");
	#endif
}

int GenerateRandomAsciiAlphabet()
{
	srand((unsigned int)time(NULL));
	return (rand() % 25 + 97);
}
string GenerateRandomId(int length)
{
	// 97 - 122
	string id = "";
	for(int i = 0; i < length; i++)
	{
		id += (char)GenerateRandomAsciiAlphabet();
	}
	return id;
}


