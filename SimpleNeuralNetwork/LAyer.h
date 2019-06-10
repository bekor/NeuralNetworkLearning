#pragma once
#include <memory>
#include <vector>
#include "Sigma.h"
#include "Neuron.h"

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

	std::vector<std::shared_ptr<Neuron>> LayerNeurons;
};

