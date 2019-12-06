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
		std::shared_ptr<Neuron> currentNeuron = std::make_shared<Neuron>(dist(rng), row);
		LayerNeurons.push_back(currentNeuron);
	}
}


std::vector<double> Layer::ForwardPropagation(std::shared_ptr<Sigma> sigma, std::vector<double> input)
{
	std::vector<double> calculatedActivation;
	for (int neuronIndex = 0; neuronIndex < _neuronCount; neuronIndex++) {

		double summ = 0;
		auto currentNeuron = LayerNeurons[neuronIndex];
		summ = currentNeuron->CalculateForwardPropagation(sigma, input);
		calculatedActivation.push_back(summ);
	}
	return calculatedActivation;
}

std::vector<double> Layer::BackwardPropagation(std::vector<std::vector<double>> nextWeight, std::vector<double> nextLinearGradient) 
{
	return std::vector<double>();
}
