#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <time.h>
#include <vector>

// Header component includes
#include "RegisterLogin.h"
#include "TextEditing.h"
#include "Menu.h"

// Std specific imports
using std::cout;
using std::cin;
using std::string;

// Global enums
enum TimeType {
	MILI,
	MICRO,
	NANO,
	MIN
};
// Helper functions
void Sleep(int amount, TimeType type_of_time);

//string file = "hi";
//editor::MakeFile("TestFile.txt");

int main() {
	
	bool logged_in = false;
	unsigned int login_attempt_counter = 3;
	account::StartUpBitTerminal();
	account::Register("ivan", "12345");
	
	while (!logged_in) {

		if (login_attempt_counter <= 0)
		{
			cout << "Too many wrong attempts. Closing application.";
			Sleep(2000, MILI);
			break;
			return 0;
		}
		std::tuple<string, string> credentials = account::PromptLogin();
		if (account::Login(std::get<0>(credentials), std::get<1>(credentials))) {
			cout << "Login succesful";
			logged_in = true;
			break;
		}
		cout << "Wrong password or username. Please try again." << std::endl;
		login_attempt_counter--;
	}

	account::ClearTerminal();
	cout << "YAY";
	return 0;
}

// Helper functions
void Sleep(int amount, TimeType type_of_time) {
	switch (type_of_time) {
		case MILI:
			std::this_thread::sleep_for(std::chrono::milliseconds(amount));
			break;
		case MICRO:
			std::this_thread::sleep_for(std::chrono::microseconds(amount));
			break;
		case NANO:
			std::this_thread::sleep_for(std::chrono::nanoseconds(amount));
			break;
		case MIN:
			std::this_thread::sleep_for(std::chrono::minutes(amount));
			break;

	}
	
}





