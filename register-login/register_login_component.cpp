#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>

using std::cout;
using std::cin;
using std::string;


// Helper function definitions
int GetStringLen(string string_to_read);


// cout function definitions
void StartUpBitTerminal(); // Prints ascii text for start-up
void Clear(); // Clears terminal based on operating system

int main() 
{
	StartUpBitTerminal();
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
