#pragma once
#include <memory>
#include <vector>
#include "Point.hpp"

class Layer
{
public:
	Layer();
	Layer(int neuronCount, int nextLayerNeuronCount);
	
	~Layer();

	std::vector<Point> OutputConvolution(std::vector<Point> input);

private:

	long _neuronCount;

	std::vector<std::vector<double>> WeightMatrix;
	std::vector<double> BiasVector;


};

