#include "Neuron.h"

Neuron::Neuron(double _bias, std::vector<double> _weights) 
			: bias(_bias), weights(_weights)
{
	linearActivation = 0.0;
	activation = 0.0;
	linearGradient = 0.0;
}

void Neuron::InitNeuron(double _bias, std::vector<double> _weights)
{
	//TODO: init every property
}

double Neuron::CalculateForwardPropagation(std::shared_ptr<Sigma> sigma, std::vector<double> input)
{
	double summ = 0;
	for (unsigned int ordinalIndex = 0; ordinalIndex < input.size(); ordinalIndex++) {
		summ += (input.at(ordinalIndex) * weights.at(ordinalIndex) + bias);
	}
	linearActivation = summ;
	return summ;
}

