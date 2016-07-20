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

	bool operator==(Termination t);
	bool haveSameParameterList(Termination t1, Termination t2);//check if the two sprite's parameter lists are the same; to be used with delete method

private:

	std::string terminationType;//type of termination this Termination object is
};

