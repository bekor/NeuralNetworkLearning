#include "pch.h"
#include "GenerateSource.h"
#include <random>
#include <iostream>
#include <fstream>
#include "Point.hpp"
#include "LinearFunction.hpp"


void GenerateSource::Generate()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1000); // distribution in range [1, 6
	std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 100);
	LinearFunction lnf = LinearFunction(dist2(rng), dist(rng));
	//LinearFunction lnf = LinearFunction(1, 1, 10);
	std::vector<Point> points;

	for (int i = 0; i < 10000; i++) {
		points.push_back(lnf.CalculatePointAroundLinearFunction(dist(rng), 1));
	}

	std::ofstream myfile("example.txt");
	if (myfile.is_open())
	{
		myfile << lnf.getSlope() << " " << lnf.getShift() << "\n\n";
		for (auto &const p : points) {
			myfile << p.getX() << " " << p.getY() << std::endl;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";


	std::cout << lnf.getShift() << " " << lnf.getSlope() << std::endl;
	Point a = lnf.CalculatePointAroundLinearFunction(1, 1);
	std::cout << a.getX() << " " << a.getY() << std::endl;
}


// Generating data source for teaching and testing network
std::vector<Point> GenerateSource::GeneratePoints(int sourceSize)
{
	// for random number generation
	std::random_device dev;
	std::mt19937 rng(dev());
	// one for the y - intercept and for the resource generation
	// one for the linear function slope
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1000);
	std::uniform_int_distribution<std::mt19937::result_type> dist100(0, 100);
	std::uniform_int<int> distDeviation(-10, 10);
	// defining the linear function
	LinearFunction lnf = LinearFunction(dist100(rng), dist(rng));
	std::vector<Point> points;

	for (int i = 0; i < sourceSize; i++) {
		points.push_back(lnf.CalculatePointAroundLinearFunction( dist(rng), distDeviation(rng)));
	}

	// creating file with the generated data

	//std::ofstream myfile("example.txt");
	//if (myfile.is_open())
	//{
	//	myfile << lnf.getSlope() << " " << lnf.getShift() << "\n\n";
	//	for (auto &const p : points) {
	//		myfile << p.getX() << " " << p.getY() << std::endl;
	//	}
	//	myfile.close();
	//}

	//// Error "log"
	//else std::cout << "Unable to open file";
	std::cout << lnf.getSlope() << " " << lnf.getShift() << std::endl;

	return points;
}

std::shared_ptr<LinkedNetwork> GenerateSource::GenerateNetwork(int weightMatrixSize, int layerCount)
{
	std::shared_ptr<LinkedNetwork> network = std::make_shared<LinkedNetwork>();
	Layer headOfNetwork = Layer(weightMatrixSize, weightMatrixSize);
	
	network->AddToEnd(headOfNetwork);
	
	layerCount--;
	
	while (layerCount > 0)
	{
		Layer next = Layer(weightMatrixSize, 2);
		network->AddToEnd(next);
		layerCount--;
	}
	
	return network;
}

