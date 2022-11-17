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
		string file_content = "";
		string line = "";
		cout << std::endl << "Editing file: " << file_name << std::endl;
		cout << "Please press SHIFT + ENTER to save your file." << std::endl;

		while (file_is_being_editted) {

			if (GetAsyncKeyState(VK_LSHIFT))
			{
				printf("File has been saved. \n");
				file << file_content;
				file.close();
				file_is_being_editted = false;
				break;
			}
			do {
				std::getline(std::cin, line);
				file_content += line + '\n';
			} while (line.length() != 0);
			line = "";
			//file << PromptEditText() << std::endl;
		}



	}

	string PromptEditText() {
		string line = "";
		cin >> line;
		return line;
	}


}









