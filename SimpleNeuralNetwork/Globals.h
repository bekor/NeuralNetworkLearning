#pragma once
#include <memory>
#include "Logger.h"

// Here maybe we shoudl store other globals like sigma.
class Globals
{
public:
	static std::shared_ptr<Globals>& getInstance();
	static std::shared_ptr<Logger> & logger;
private:
	Globals();
	static std::shared_ptr<Globals> instance;
};

