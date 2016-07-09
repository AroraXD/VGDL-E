#include "Parameter.h"
#include "Manager.h"




Parameter::Parameter(std::string name, int value)
{
	parameterName = name;
	parameterValue = Manager::toString(value);
	parameterType = 1;
}

Parameter::Parameter(std::string name, float value)
{
	parameterName = name;
	parameterValue = Manager::toString(value);
	parameterType = 2;
}

Parameter::Parameter(std::string name, bool value)
{
	parameterName = name;
	parameterValue = Manager::toString(value);
	parameterType = 3;

}

Parameter::Parameter(std::string name, std::string value)
{
	parameterName = name;
	parameterValue = value;
	parameterType = 4;
}

Parameter::~Parameter()
{
}
