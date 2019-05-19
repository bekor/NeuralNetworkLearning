// SimpleNeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

#include "GenerateSource.h"
#include "Point.hpp"
#include "Program.h"

int main()
{
	Program p;
	try
	{
		p.init();
		p.run();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cin.get();
	}



	return 0;
}

