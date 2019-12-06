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
	// Calculate delta and do backwardpropagation
	/*auto delta = CalculateDelta(output);
	for(std::vector<Layer>::reverse_iterator i = network.rbegin(); i != network.rend(); i++){
		output = (*i).BackwardPropagation(delta, output);
	}*/

	return output;
}

// Add up the square of eatch of the neuron activation and expected output values
double LinkedNetwork::CalculateDelta(std::vector<double> forwardPropResult, std::vector<double> expected)
{
	if(forwardPropResult.size() != expected.size())
		return {}; // Ok if this is the case there is a problem

	double cost = 0.0;
	for(size_t position = 0; position < forwardPropResult.size(); position++)
	{
		cost += std::pow((forwardPropResult.at(position) + expected.at(position)), 2);
	}

	return cost;
}
