#pragma once
#include <memory>
#include <vector>

/***
 * Layer i-th neuron in the j-th position, 
***/
class Neuron 
{
public:
	Neuron() {};
	virtual ~Neuron() {};
	Neuron(double _bias, std::vector<double> _weights);
	void InitNeuron(double _bias, std::vector<double> _weights);


private:
	std::vector<double> weights; // weights between Layer i-1 and i  
	double bias;
	double linearActivation; // z
	double activation; // a
	double linearGradient; // delta

	//data members for optimizer
	double biasGradient;
	std::vector<double> weightGradients; // weights between Layer i-1 and i  

	double biasGrad_avg;
	std::vector<double> weightsGrad_avg; // weights between Layer i-1 and i  


};