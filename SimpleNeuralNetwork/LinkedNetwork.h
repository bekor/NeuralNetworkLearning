#pragma once

#include "Node.hpp"
#include "Layer.h"
#include "Point.hpp"
#include "Sigma.h"

class LinkedNetwork
{
protected:
	std::shared_ptr<Node> head = nullptr;
	std::shared_ptr<Node> tail = nullptr;

public:
	LinkedNetwork();
	virtual ~LinkedNetwork() {}

	void AddToEnd(Layer value);

	std::vector<Point> RunNetwork(std::vector<Point> input);

private:
	Sigma sigma;
	std::shared_ptr<Node> CreateNode(Layer value);

};

