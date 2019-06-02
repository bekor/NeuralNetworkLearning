#pragma once
#include <memory>
#include <vector>
#include "Sigma.h"

class Layer
{
public:
	Layer(); // do not use this one, ever

	Layer(int prevNeuronCount, int neuronCount);

	~Layer();

	std::vector<double> ForwardPropagation(std::shared_ptr<Sigma> sig, std::vector<double> prevActivation);
	std::vector<double> BackwardPropagation(std::vector<std::vector<double>> nextWeight,std::vector<double> nextLinearGradient );
private:
	void InitLayer(int prevNeuronCount, int neuronCount);

	long _neuronCount;

	// Forward propagation variable
	std::vector<double> BiasVector; // every node hase one bias
	std::vector<std::vector<double>> WeightMatrix; // every node has n weight (depends on the previous layer neuron count)

	std::vector<double> NeuronLinearActivation; // z
	std::vector<double> NeuronActivation; // a
	std::vector<double> LinearGradient; // delta

	std::vector<double> BiasVectorGrad;
	std::vector<std::vector<double>> WeightMatrixGrad;


	std::vector<double> BiasVectorGrad_avg;
	std::vector<std::vector<double>> WeightMatrixGrad_avg;

	

};

