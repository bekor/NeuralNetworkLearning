#pragma once

/***
 * Sigma will determine the function which will normalize the calculated weight on a node
 * We are using a well defined sigma function for every network. It depends on the initialization.
 * So further task: define derived class(es) for sigma (sigmoid function, tangent etc.)
***/
class Sigma
{
public:
	Sigma() {};
	virtual ~Sigma() {};

	virtual void SigmaFunction() = 0;
};

