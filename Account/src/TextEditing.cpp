#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <filesystem>
#include <thread>
#include <windows.h>

namespace fs = std::filesystem;

using std::cin;
using std::cout;
using std::string;

namespace editor // Text editor namespace
{
	string PromptEditText();
	//TASKS: 
	//1) Creating files in compile time given name
	//2) Opening files in compile time given name
	//3) Writing on files in compile time
	//4) Saving files in compile time

	void MakeFile(string file_name)
	{ 
		std::ofstream file;
		string path = R"(.\\TextFolder\\)";
		file.open(path + file_name);
		file.close();
	}

	void EditFile(std::string file_name) {

		bool file_is_being_editted = false;
		string path = R"(.\\TextFolder\\)";
		std::ofstream file;
		string compare_path = R"(\\\\TextFolder\\\\)";

		file.open(path + file_name);
		file_is_being_editted = true;
		cout << "Editing file: " << file_name << std::endl;
		while (file_is_being_editted) {
			if (GetAsyncKeyState(VK_LSHIFT))
			{
				printf("File has been saved. \n");
				file.close();
				file_is_being_editted = false;
				continue;
			}
			file << PromptEditText();
		}

	}
	void SaveFile() {

	}

	string PromptEditText() {
		string line = "";
		cin >> line;
		return line;
	}


}









