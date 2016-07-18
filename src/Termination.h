#pragma once

#include <string>
#include <vector>
#include "ParameterizableObj.h"

class Termination : public ParameterizableObj
{
public:
	Termination(std::string terminationName);
	Termination(std::string terminationName, std::vector<Parameter> paramList);
	~Termination();



	void setTerminationType(std::string newType);
	std::string getTerminationType();



private:

	std::string terminationType;//type of termination this Termination object is
};

