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
	LinearFunction lnf = LinearFunction(dist2(rng), dist(rng), 10);
	//LinearFunction lnf = LinearFunction(1, 1, 10);
	std::vector<Point> points;

	for (int i = 0; i < 10000; i++) {
		points.push_back(Point::CalculatePointFromLinearFunction(lnf, dist(rng)));
	}

	std::ofstream myfile("example.txt");
	if (myfile.is_open())
	{
		myfile << lnf.getSlope() << " " << lnf.getShift() << "\n\n";
		for (auto &const p : points) {
			myfile << p.x << " " << p.y << std::endl;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";


	std::cout << lnf.getShift() << " " << lnf.getSlope() << std::endl;
	Point a = Point::CalculatePointFromLinearFunction(lnf, 1);
	std::cout << a.x << " " << a.y << std::endl;
}

std::vector<Point> GenerateSource::GeneratePoints()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1000); // distribution in range [1, 6
	std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 100);
	LinearFunction lnf = LinearFunction(dist2(rng), dist(rng), 10);
	//LinearFunction lnf = LinearFunction(1, 1, 10);
	std::vector<Point> points;

	for (int i = 0; i < 10000; i++) {
		points.push_back(Point::CalculatePointFromLinearFunction(lnf, dist(rng)));
	}

	std::ofstream myfile("example.txt");
	if (myfile.is_open())
	{
		myfile << lnf.getSlope() << " " << lnf.getShift() << "\n\n";
		for (auto &const p : points) {
			myfile << p.x << " " << p.y << std::endl;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
	std::cout << lnf.getSlope() << " " << lnf.getShift() << std::endl;
	return points;
}

std::shared_ptr<Layer> GenerateSource::GenerateNetwork(int size)
{
	std::shared_ptr<Layer> head = std::make_shared<Layer>(size, size);
	std::shared_ptr<Layer> next = std::make_shared<Layer>(size, 2);
	head->_next = next;
	next->_prev = head;
	
	return head;
}

