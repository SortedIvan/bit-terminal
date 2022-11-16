#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include <stdlib.h>
#include <thread>

using std::string;
using std::cout;
using std::cin;

namespace menu {

	const int menu_options_amnt = 3;
	string menu_options[menu_options_amnt] = {
		"1) Open Text Editor",
		"2) Open Games Menu",
		"3) Logout"
	};

	void ShowMenuOptions() 
	{
		for (int i = 0; i < menu_options_amnt; i++)
		{
			cout << menu_options[i];
			std::this_thread::sleep_for(std::chrono::microseconds(100));
		}
	}


}