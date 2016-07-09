#pragma once
#include <string>

class Parameter
{
public:
	Parameter(std::string name, int value);
	Parameter(std::string name, float value);
	Parameter(std::string name, std::string value);

	~Parameter();

private:
	std::string parameterName;
	int parameterIntValue;
	float parameterFloatValue;
	std::string parameterStrValue;//because the parameter may be a string, a float or an int...there has to be a better way to deal with this
	int parameterType;//1=int, 2=float, 3=string
};

