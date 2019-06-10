#pragma once

/* Command line arguments can define some the program behaviour
 * -t making a traning based on program default parameters
 * -tp <Path> <format> tells the program you want to train a new network
 *					  based on a <Path>file which contains the traning data in a defined <format>
 * -rp <Path> <format> using an existing network to predict the output of the file intpu <Path>
 *					  which contains the format of the input
*/
class ArgumentHandler
{
public:
	ArgumentHandler();
	ArgumentHandler(int argc, char *argv[]);
	virtual ~ArgumentHandler();
	void PrintUsage();
};

