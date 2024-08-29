#pragma once
#include "Utilities.h"

class ISimulation // base class for all simulations
{
public:
	// simulation information
	static std::string simulationMethodName;
	int simulationID;

	// every simulation must have run(), and possibly more which I will add in time
	virtual bool run();
	virtual void printInformation();
};