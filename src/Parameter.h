#pragma once
#include <string>

//Generic parameter, can be used by any class. The paramaters it can be depends on the class that's calling them(Sprite, Interaction or Termination).

class Parameter
{
public:
	Parameter(std::string name, int value);
	Parameter(std::string name, float value);
	Parameter(std::string name, bool value);
	Parameter(std::string name, std::string value);

	~Parameter();

	std::string getParameterName();
	void setParameterName(std::string newName);

	std::string getParameterValue();
	void setParameterValue(std::string newValue);

	int getParameterType();
	void setParameterType(int newParameterType);

	bool operator==(Parameter p);

private:
	std::string parameterName;
	//because the parameter may be a string, a float or an int, we simply cast them all to strings, since we'll only use them to create the script
	std::string parameterValue;

	int parameterType;//1=int, 2=float, 3=bool, 4=string
};

