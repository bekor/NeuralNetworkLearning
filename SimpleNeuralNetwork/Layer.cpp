#include "pch.h"
#include "Layer.h"
#include <random>
#include "Point.hpp"


Layer::Layer()
{
	_neuronCount = 0;
}

Layer::Layer(int neuronCount, int nextLayerNeuronCount)
	: _neuronCount(nextLayerNeuronCount)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> dist(0, 1);
	for (int weightMatrixHeight = 0; weightMatrixHeight < neuronCount; weightMatrixHeight++) {
		std::vector<double> row;
		for (int weightMatrixWidth = 0; weightMatrixWidth < nextLayerNeuronCount; weightMatrixWidth++)
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

std::vector<Point> Layer::OutputConvolution(std::vector<Point> input)
{
	std::vector<Point> output;

	for (int neuron = 0; neuron < _neuronCount; neuron++) {

		double summX = 0;
		double summY = 0;

		for (int ordinal = 0; ordinal < input.size(); ordinal++) {
			summX += (input[ordinal].x * WeightMatrix[ordinal][neuron] + BiasVector[ordinal]);
			summY += (input[ordinal].y * WeightMatrix[ordinal][neuron] + BiasVector[ordinal]);
		}

		output.push_back(Point(summX, summY));
	}

	if (_next != nullptr) {
		return _next->OutputConvolution(output);
	}
	else
		return output;
}
