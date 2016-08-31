#pragma once
#include "ParameterizableObj.h"
class GlobalGameParameters :public ParameterizableObj
{
public:
	GlobalGameParameters();
	~GlobalGameParameters();


private:

	//already inherits from ParameterizableObj, so already has a list of Parameters
};

