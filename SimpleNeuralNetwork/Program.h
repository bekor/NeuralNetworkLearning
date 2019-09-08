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
	void FlattenPointInput(std::vector<std::shared_ptr<Point>> input);
	std::vector<double> m_FlattenedInput;
	std::shared_ptr<LinkedNetwork> m_Network;
};

