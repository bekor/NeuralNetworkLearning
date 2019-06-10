#pragma once
#include <memory>
#include "Logger.h"

// Here maybe we shoudl store other globals like sigma.
class Globals
{
public:
	std::shared_ptr<Globals>& getInstance();
	std::shared_ptr<Logger> logger;
private:
	Globals();
	std::shared_ptr<Globals> instance;
};

