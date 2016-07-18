#include "ParameterizableObj.h"



ParameterizableObj::ParameterizableObj()
{
}


ParameterizableObj::~ParameterizableObj()
{
}

std::vector<Parameter> ParameterizableObj::getParameterList()
{
	return parameterList;
}

void ParameterizableObj::setParameterList(std::vector<Parameter> newParameterList)
{
	parameterList = newParameterList;
}

void ParameterizableObj::addParameter(Parameter newParameter)
{
	parameterList.push_back(newParameter);
}
