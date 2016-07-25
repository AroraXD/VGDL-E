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

bool Termination::operator==(Termination t)
{
	return (this->getTerminationType() == t.getTerminationType() && haveSameParameterList(*this, t));
}

void Termination::operator=(Termination t)
{
	this->terminationType = t.getTerminationType();
	this->parameterList = t.getParameterList();
}

bool Termination::haveSameParameterList(Termination t1, Termination t2)
{
	//if they're not even the same size, goes straight to false
	if (t1.getParameterList().size() != t2.getParameterList().size())
		return false;
	else//same size, so we check item by item
	{
		for (int i = 0; i < t1.getParameterList().size(); i++)
		{
			if (!(t1.getParameterList()[i] == t2.getParameterList()[i]))//diff name or value, ergo diff parameter
			{
				return false;
			}

		}

	}
	//after all tests, if it got here, means it has the same parameter list
	return true;
}
