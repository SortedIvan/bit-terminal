#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <time.h>
#include <vector>

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
bool Login(string username, string password);
std::tuple<string, string> PromptLogin();
bool CheckCredentials(string username, string password, std::vector<string> credentials);

int main() 
{
	StartUpBitTerminal();
	Register("Vankata", "12345");
	std::tuple<string, string> credentials = PromptLogin();

	if (Login(std::get<0>(credentials), std::get<1>(credentials))) {
		cout << "Login succesful";
		return 0;
	}
	cout << "Login unsuccesful";
	return 0;
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
	account_file << "ACCOUNT_ID:" << account_id << ",";
	account_file << "ACCOUNT_USERNAME:" << username << ",";
	account_file << "ACCOUNT_PASSWORD:" << password << '\n';
	account_file.close();
}

bool Login(string username, string password) {
	string line;
	std::ifstream account_file;
	account_file.open("accounts.txt");

	if (account_file.is_open())
	{
		while (getline(account_file, line))
		{
			string delimiter = ","; // Comma seperated values, seperator
			std::vector<string> credentials; // Storing the credentials here
			size_t last = 0; 
			size_t next = 0; 
			while ((next = line.find(delimiter, last)) != std::string::npos) 
			{ 
				//std::cout << line.substr(last, next - last) << std::endl; 
				credentials.push_back(line.substr(last, next - last));
				last = next + 2; 
			} 
			credentials.push_back(line.substr(last)); // Getting the last element for credentials

			for (int i = 0; i < credentials.size(); i++)
			{
				string credential = credentials[i].substr(credentials[i].find(":") + 1); // Seperating credential value from credential specifier
				credentials[i] = credential; // Reusing credentials vector to store actual value
			}
			
			if (CheckCredentials(username, password, credentials)) 
			{
				account_file.close();
				return true;
			}
		}
		account_file.close();
	}
	return false;
}

std::tuple<string, string> PromptLogin() {
	string username = "";
	string password = "";
	std::tuple <string, string> credentials;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	credentials = std::make_tuple(username, password);
	return credentials;
}

bool CheckCredentials(string username, string password, std::vector<string> credentials)
{
	if (credentials[1] == username && credentials[2] == password)
	{
		return true;
	}
	return false;
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


