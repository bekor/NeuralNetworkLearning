#include "pch.h"
#include "Layer.h"
#include <random>
#include "Point.hpp"


Layer::Layer()
{
	_neuronCount = 0;
}

Layer::Layer(int prevneuronCount, int neuronCount)
	: _neuronCount(neuronCount)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> dist(0, 1);
	for (int weightMatrixHeight = 0; weightMatrixHeight < prevneuronCount; weightMatrixHeight++) {
		std::vector<double> row;
		for (int weightMatrixWidth = 0; weightMatrixWidth < neuronCount; weightMatrixWidth++)
		{
			row.push_back(dist(rng));
		}
		WeightMatrix.push_back(row);
		BiasVector.push_back(dist(rng));
	}

}



Layer::~Layer()
{
}

std::vector<Point> Layer::ForwardPropagation(Sigma sigma, std::vector<Point> input)
{
	NeuronLinearActivation.clear();
	for (int neuron = 0; neuron < _neuronCount; neuron++) {

		double summX = 0;
		double summY = 0;

		for (unsigned int ordinal = 0; ordinal < input.size(); ordinal++) {
			summX += (input[ordinal].getX() * WeightMatrix[ordinal][neuron] + BiasVector[ordinal]);
			summY += (input[ordinal].getY() * WeightMatrix[ordinal][neuron] + BiasVector[ordinal]);
		}

		NeuronLinearActivation.push_back(Point(summX, summY));

	}
	return NeuronLinearActivation;
}
