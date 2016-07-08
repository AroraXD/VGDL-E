#pragma once
#include <string>

class SpriteParameter
{
public:
	SpriteParameter(std::string name, int value);
	SpriteParameter(std::string name, float value);
	SpriteParameter(std::string name, std::string value);

	~SpriteParameter();

private:
	std::string parameterName;
	int parameterIntValue;
	float parameterFloatValue;
	std::string parameterStrValue;//because the parameter may be a string, a float or an int...there has to be a better way to deal with this
	int parameterType;//1=int, 2=float, 3=string
};

