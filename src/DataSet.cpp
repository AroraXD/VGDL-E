#include "DataSet.h"



DataSet::DataSet()
{
}


DataSet::~DataSet()
{
}


std::vector<std::string> DataSet::getSpriteTypeList()
{
	return spriteTypeList;
}

std::vector<std::string> DataSet::getColorList()
{
	return colorList;
}

std::vector<std::string> DataSet::getSpriteParameterList()
{
	return spriteParameterList;
}


std::vector<std::string> DataSet::getInteractionTypeList()
{
	return interactionTypeList;
}

std::vector<std::string> DataSet::getInteractionParametersList()
{
	return interactionParametersList;
}