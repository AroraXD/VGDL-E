#include "Termination.h"





Termination::Termination(std::string terminationName)
{
	terminationType = terminationName;
}

Termination::Termination(std::string terminationName, std::vector<Parameter> paramList)
{
	terminationType = terminationName;
	parameterList = paramList;
}

Termination::~Termination()
{
}

void Termination::setTerminationType(std::string newType)
{
	terminationType = newType;
}

std::string Termination::getTerminationType()
{
	return terminationType;
}
