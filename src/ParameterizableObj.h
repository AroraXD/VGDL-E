#pragma once

#include <vector>
#include <string>
#include "Parameter.h"

class ParameterizableObj
{
public:
	ParameterizableObj();
	~ParameterizableObj();

	std::vector<Parameter> getParameterList();
	void setParameterList(std::vector<Parameter> newParameterList);
	void addParameter(Parameter newParameter);
	void deleteParameterAtPosition(int i);

protected:
	//will pass along to kids


	std::vector<Parameter> parameterList;//one sprite can have a lot of parameters



};

