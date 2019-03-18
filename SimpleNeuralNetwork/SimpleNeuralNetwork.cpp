// SimpleNeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "GenerateSource.h"
#include "Point.hpp"

int main()
{
	std::vector<Point> input =  GenerateSource::GeneratePoints();
	std::shared_ptr<Layer> network = GenerateSource::GenerateNetwork(10);

	input.resize(10);

	std::vector<Point> output = network->OutputConvolution(input);

	for (auto & const p : output) {
		std::cout << p.x << " " << p.y << "\n";
	}

	float slope = (output.at(1).y - output.at(0).y) / (output.at(1).x - output.at(0).x);
	float intercetp = output.at(0).y + slope * output.at(0).x;

	std::cout << "Slope: " << slope
		<< " y-intercept: " << intercetp << "\n";


	char c;
	std::cin >> c;
}

