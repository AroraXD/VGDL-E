#include "Parameter.h"





Parameter::Parameter(std::string name, int value)
{
	parameterName = name;
	parameterIntValue = value;
	parameterType = 1;
}

Parameter::Parameter(std::string name, float value)
{
	parameterName = name;
	parameterFloatValue = value;
	parameterType = 2;
}

Parameter::Parameter(std::string name, std::string value)
{
	parameterName = name;
	parameterStrValue = value;
	parameterType = 3;
}

Parameter::~Parameter()
{
}
