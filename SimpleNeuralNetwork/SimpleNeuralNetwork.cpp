// SimpleNeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

#include "GenerateSource.h"
#include "Point.hpp"
//#include "Program.h"

int main()
{
	//Program p;
	//try
	//{
	//	p.init();
	//	p.run();
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//	std::cin.get();
	//}

	std::vector<Point> input = GenerateSource::GeneratePoints(10);
	std::shared_ptr<LinkedNetwork> network = GenerateSource::GenerateNetwork(10, 2);
	input.resize(10);

	std::vector<Point> output = network->RunNetwork(input);

	for (auto & const p : output) {
		std::cout << p.getX() << " " << p.getY() << "\n";
	}

	double slope = (output.at(1).getY() - output.at(0).getY()) 
				/ (output.at(1).getX() - output.at(0).getX());

	double intercetp = output.at(0).getY() + slope * output.at(0).getX();

	std::cout << "Slope: "		  << std::to_string(slope)
			  << " y-intercept: " << std::to_string(intercetp) << "\n";

	return 0;
}

