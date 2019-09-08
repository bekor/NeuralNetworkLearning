#pragma once

#include "Node.hpp"
#include "Layer.h"
#include "Point.hpp"
#include "Sigma.h"

class LinkedNetwork
{
protected:
	std::vector<Layer> network;

public:
	LinkedNetwork();
	virtual ~LinkedNetwork() {}

	void AddToEnd(Layer value);

	std::vector<double> TrainNetwork(std::vector<double> input);

private:
	double CalculateDelta(std::vector<double> forwardPropResult, std::vector<double> expected);
	std::shared_ptr<Sigma> sigma;
};

