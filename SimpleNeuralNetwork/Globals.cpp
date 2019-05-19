#include "pch.h"
#include "Globals.h"


std::shared_ptr<Globals>& Globals::getInstance()
{
	if (!instance) {
		instance = std::shared_ptr<Globals>(new Globals());
	}
	return instance;
}

Globals::Globals()
{
	// here we init our logger and every other stuff we will use in other global purpuse
	logger = std::shared_ptr<Logger>(new Logger());
}
