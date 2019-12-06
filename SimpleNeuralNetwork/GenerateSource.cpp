#include <random>
#include <iostream>
#include <fstream>
#include <memory>

#include "Point.hpp"
#include "GenerateSource.h"
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
		points.push_back(lnf.CalculatePointAroundLinearFunctionObj(dist(rng), 1));
	}

	std::ofstream myfile("example.txt");
	if (myfile.is_open())
	{
		myfile << lnf.getSlope() << " " << lnf.getShift() << "\n\n";
		for (auto &p : points) {
			myfile << p.getX() << " " << p.getY() << std::endl;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";


	std::cout << lnf.getShift() << " " << lnf.getSlope() << std::endl;
	Point a = lnf.CalculatePointAroundLinearFunctionObj(1, 1);
	std::cout << a.getX() << " " << a.getY() << std::endl;
}


// Generating data source for teaching and testing network
std::vector<std::shared_ptr<Point>> GenerateSource::GeneratePoints(int sourceSize)
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
	std::vector<std::shared_ptr<Point>> points;

	for (int i = 0; i < sourceSize; i++) {
		points.push_back(lnf.CalculatePointAroundLinearFunction( dist(rng), distDeviation(rng)));
	}

	std::cout << lnf.getSlope() << " " << lnf.getShift() << std::endl;

	return points;
}

// Creating the fully connected network without upscaling or down scaling
// Just the last layer size is defined by the program (right now)
std::shared_ptr<LinkedNetwork> GenerateSource::GenerateNetwork(size_t weightMatrixSize, int layerCount)
{
	std::shared_ptr<LinkedNetwork> network = std::make_shared<LinkedNetwork>();
	
	while (layerCount > 1)
	{
		Layer next = Layer(weightMatrixSize, weightMatrixSize);
		network->AddToEnd(next);
		layerCount--;
	}
	if (layerCount == 1) {
		// We do not check eni format for input, we preparing it to predict for two output
		Layer next = Layer(weightMatrixSize, 2);
	}
	
	return network;
}

