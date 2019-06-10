#include "pch.h"
#include "LinkedNetwork.h"


LinkedNetwork::LinkedNetwork()
{
}

void LinkedNetwork::AddToEnd(Layer value)
{
	network.push_back(value);
}

std::vector<double> LinkedNetwork::TrainNetwork(const std::vector<double> input)
{
	std::vector<double> output = input;
	for( auto& layer : network) {
		output = layer.ForwardPropagation(sigma, output);
	}
	return output;
}