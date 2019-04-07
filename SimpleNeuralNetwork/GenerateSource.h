#pragma once

#include "Layer.h"
#include "LinkedNetwork.h"
class GenerateSource
{
public:
	static void Generate();
	static std::vector<Point> GeneratePoints(int sourceSize);

	static std::shared_ptr<LinkedNetwork> GenerateNetwork(int weightMatrixSize, int layerCount = 1);
};

