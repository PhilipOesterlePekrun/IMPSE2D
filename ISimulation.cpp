#include "ISimulation.h"

bool ISimulation::run()
{
	return 0; // error
}
std::string* ISimulation::simulationInformation()
{
	std::string arr[1]= {"ERROR: ISimulation should not be instantiated"};
	return arr;
}; // maybe throw an error if trying to print with interface