#include "Manager.h"



Manager::Manager()
{
}


Manager::~Manager()
{
}

std::string Manager::toString(int i)
{
	return std::to_string(i);
}

std::string Manager::toString(float f)
{
	return std::to_string(f);
}

std::string Manager::toString(bool b)
{
	if (b)
		return "True";//VGDL reads True or False with capitals, look out for that

	return "False";
}
