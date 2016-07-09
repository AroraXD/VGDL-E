#pragma once

#include <string>

//The manager class will be used for miscellaneous functions, like transforming diferent variables into strings so they can be more easily placed in the VGDL script


class Manager
{
public:
	Manager();
	~Manager();
	
	static std::string toString(int i);
	static std::string toString(float f);
	static std::string toString(bool b);

};

