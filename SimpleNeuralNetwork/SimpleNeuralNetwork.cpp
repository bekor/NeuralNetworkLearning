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
		std::cout << p.x << " " << p.y << "\n";
	}

	float slope = (output.at(1).y - output.at(0).y) / (output.at(1).x - output.at(0).x);
	float intercetp = output.at(0).y + slope * output.at(0).x;

	std::cout << "Slope: "		  << std::to_string(slope)
			  << " y-intercept: " << std::to_string(intercetp) << "\n";

	return 0;
}

