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

	std::vector<double> RunNetwork(std::vector<double> input);

private:
	std::shared_ptr<Sigma> sigma;
};

