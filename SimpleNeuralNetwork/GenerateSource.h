#pragma once

#include "Layer.h"

class GenerateSource
{
public:
	static void Generate();
	static std::vector<Point> GeneratePoints();

	static std::shared_ptr<Layer> GenerateNetwork(int size);
};

