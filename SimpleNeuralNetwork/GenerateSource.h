#pragma once

#include <memory>

#include "Layer.h"
#include "LinkedNetwork.h"

class GenerateSource
{
public:
	static void Generate();
	static std::vector<std::shared_ptr<Point>> GeneratePoints(int sourceSize);

	static std::shared_ptr<LinkedNetwork> GenerateNetwork(size_t weightMatrixSize, int layerCount = 1);
};

