#pragma once
#include <memory>
#include <vector>
#include "Point.hpp"
#include "Sigma.h"

class Layer
{
public:
	Layer();
	Layer(int prevneuronCount, int neuronCount);
	
	~Layer();

	std::vector<Point> ForwardPropagation(Sigma sig, std::vector<Point> prevActivation);
	std::vector<double> BackwardPropagation(std::vector<std::vector<double>> nextWeight,std::vector<double> nextLinearGradient );
private:

	long _neuronCount;

	std::vector<std::vector<double>> WeightMatrix;
	std::vector<double> BiasVector;
	std::vector<Point> NeuronLinearActivation; // z
	std::vector<double> NeuronActivation; // a
	std::vector<double> LinearGradient; // delta
	std::vector<double> BiasVectorGrad;
	std::vector<std::vector<double>> WeightMatrixGrad;
	

};

