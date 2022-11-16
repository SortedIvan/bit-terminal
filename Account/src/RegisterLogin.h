#pragma once
#include <string>

namespace account {
	void StartUpBitTerminal();
	void Register(std::string username, std::string password);
	bool Login(std::string username, std::string password);
	void ClearTerminal();
	std::tuple<std::string, std::string> PromptLogin();
	std::tuple<std::string, std::string> PromptRegister();
}


