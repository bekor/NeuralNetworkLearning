#include "ArgumentHandler.h"
#include <iostream>

ArgumentHandler::ArgumentHandler()
{
}


ArgumentHandler::ArgumentHandler(int argc, char * argv[])
{
	if (argc < 1)
		PrintUsage();
	else {
		// the first argument is the file path
		for (int i = 1; i < argc; i++)
		{
			std::string parse = argv[i];
			// TODO other input handling
			if (parse[0] == '-') {
				if (parse[1] == 't' || parse.length() == 2) {
					return; 
				}
			}
			else {
				PrintUsage();
			}
		}
	}
}


ArgumentHandler::~ArgumentHandler()
{
}

void ArgumentHandler::PrintUsage()
{
	std::cout << "HELP Menu\n";
	std::cout << "Expected input format:\n";
	std::cout << "-t making a traning based on program default parameters";
}
