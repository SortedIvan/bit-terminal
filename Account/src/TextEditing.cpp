#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

namespace editor // Text editor namespace
{
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



}









