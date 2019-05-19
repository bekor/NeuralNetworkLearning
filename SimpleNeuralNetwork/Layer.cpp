#include "pch.h"
#include "Layer.h"
#include <random>
#include "Point.hpp"


Layer::Layer()
{
	_neuronCount = 0;
}

Layer::Layer(int prevNeuronCount, int neuronCount)
	: _neuronCount(neuronCount)
{
	InitLayer(prevNeuronCount, neuronCount);
}

Layer::~Layer()
{
}

void Layer::InitLayer(int prevNeuronCount, int neuronCount)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> dist(0, 1);
	for (int weightMatrixHeight = 0; weightMatrixHeight < prevNeuronCount; weightMatrixHeight++) {
		std::vector<double> row;
		for (int weightMatrixWidth = 0; weightMatrixWidth < neuronCount; weightMatrixWidth++)
		{
			row.push_back(dist(rng));
		}
		WeightMatrix.push_back(row);
		BiasVector.push_back(dist(rng));
	}
}


std::vector<double> Layer::ForwardPropagation(std::shared_ptr<Sigma> sigma, std::vector<double> input)
{
	NeuronLinearActivation.clear();
	for (int neuron = 0; neuron < _neuronCount; neuron++) {

		double summ = 0;

		for (unsigned int ordinal = 0; ordinal < input.size(); ordinal++) {
			summ += (input[ordinal] * WeightMatrix[ordinal][neuron] + BiasVector[neuron]); //TODO: check this calculation!
		}
		NeuronLinearActivation.push_back(summ);
	}
	return NeuronLinearActivation;
}

std::vector<double> Layer::BackwardPropagation(std::vector<std::vector<double>> nextWeight, std::vector<double> nextLinearGradient) 
{
	return std::vector<double>();
}
