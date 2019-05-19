#include "pch.h"
#include "Program.h"
#include "GenerateSource.h"

Program::Program() : network(nullptr)
{
}


Program::~Program()
{
}

void Program::init()
{
	std::vector<Point> inputPoints = GenerateSource::GeneratePoints(1000);
	network = GenerateSource::GenerateNetwork(10, 2);

}

void Program::run()
{

	std::vector<double> output = network->RunNetwork(_flattenedInput);

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
