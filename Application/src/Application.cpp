#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <time.h>
#include <vector>
#include "RegisterLogin.h"
// Std specific imports
using std::cout;
using std::cin;
using std::string;


int main() {
	account::StartUpBitTerminal();
	account::Register("Test", "12345");
	std::tuple<string, string> credentials = account::PromptLogin();
	if (account::Login(std::get<0>(credentials), std::get<1>(credentials))) {
		cout << "Login succesful";
		return 0;
	}
	cout << "Login unsuccesful";
	return 0;

}
//int main()
//{
//	StartUpBitTerminal();
//	Register("Vankata", "12345");
//	

//	if (Login(std::get<0>(credentials), std::get<1>(credentials))) {
//		cout << "Login succesful";
//		return 0;
//	}
//	cout << "Login unsuccesful";
//	return 0;
//}
