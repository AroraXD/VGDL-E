#include "Parameter.h"
#include "Manager.h"




Parameter::Parameter()
{
}

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

std::string Parameter::getParameterName()
{
	return parameterName;
}

void Parameter::setParameterName(std::string newName)
{
	parameterName = newName;
}

std::string Parameter::getParameterValue()
{
	return parameterValue;
}

void Parameter::setParameterValue(std::string newValue)
{
	parameterValue = newValue;
}

int Parameter::getParameterType()
{
	return parameterType;
}

void Parameter::setParameterType(int newParameterType)
{
	parameterType = newParameterType;
}

bool Parameter::operator==(Parameter p)
{
	return (this->getParameterName() == p.getParameterName() && this->getParameterValue() == p.getParameterValue() && this->getParameterType() == p.getParameterType());
}
