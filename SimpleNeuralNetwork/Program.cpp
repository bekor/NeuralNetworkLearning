#include "pch.h"
#include "Program.h"
#include "GenerateSource.h"

Program::Program() : m_Network(nullptr)
{
}


Program::~Program()
{
}

void Program::init()
{
	// At first we try it with something we define
	std::vector<Point> inputPoints = GenerateSource::GeneratePoints(10);
	m_Network = GenerateSource::GenerateNetwork(inputPoints.size(), 10);

	// Here we should flatten any input
	FlattenPointInput(inputPoints);
}

void Program::run()
{

	std::vector<double> output = m_Network->TrainNetwork(m_FlattenedInput);

	// specific actions, based on the expectied output.
	//for (auto & const p : output) {
	//	std::cout << p.getX() << " " << p.getY() << "\n";
	//}

	//double slope = (output.at(1).getY() - output.at(0).getY())
	//	/ (output.at(1).getX() - output.at(0).getX());

	//double intercetp = output.at(0).getY() + slope * output.at(0).getX();

	//std::cout << "Slope: " << std::to_string(slope)
	//	<< " y-intercept: " << std::to_string(intercetp) << "\n";
}

// Flattening X, Y pairs into a vector of long. 
// Points has a function we do not care about the logic of flattening, just jusing it's function
void Program::FlattenPointInput(std::vector<Point> input)
{
	m_FlattenedInput = Point::Flattened(input);
}
