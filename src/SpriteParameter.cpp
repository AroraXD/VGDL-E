#include "SpriteParameter.h"





SpriteParameter::SpriteParameter(std::string name, int value)
{
	parameterName = name;
	parameterIntValue = value;
	parameterType = 1;
}

SpriteParameter::SpriteParameter(std::string name, float value)
{
	parameterName = name;
	parameterFloatValue = value;
	parameterType = 2;
}

SpriteParameter::SpriteParameter(std::string name, std::string value)
{
	parameterName = name;
	parameterStrValue = value;
	parameterType = 3;
}

SpriteParameter::~SpriteParameter()
{
}
