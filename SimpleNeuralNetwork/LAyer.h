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


	std::weak_ptr<Layer> _prev;
	std::shared_ptr<Layer> _next;
private:

	long _neuronCount;

	std::vector<std::vector<double>> WeightMatrix;
	std::vector<double> BiasVector;


};

