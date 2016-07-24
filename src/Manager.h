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

	static void capitalizeInitial(std::string input);//capitalizes first letter of the string
	static void decapitalizeInitial(std::string input);//opposite of method above

	static bool isAlphabetic(std::string input);//check if input is alphabetic, i.e., if all chars in it are letters

};

