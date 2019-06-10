#pragma once

#include <vector>
#include <memory>
#include "Point.hpp"
#include "LinkedNetwork.h"

class Program
{
public:
	Program();
	~Program();
	void init();
	void run();
private:
	std::vector<double> _flattenedInput;
	std::shared_ptr<LinkedNetwork> network;
};

