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

std::vector<std::string> DataSet::getTerminationTypeList()
{
	return terminationTypeList;
}

std::vector<std::string> DataSet::getTerminationParameterList()
{
	return terminationParameterList;
}

bool DataSet::isValidSpriteType(std::string sType)
{
	for (int i = 0; i < spriteTypeList.size(); i++)
	{
		if (sType == spriteTypeList[i])
		{
			return true;
		}
	}
	return false;//didn't find sType inside spriteTypeList
}

bool DataSet::isValidAvatar(std::string av)
{
	for (int i = 0; i < 8; i++)//8 because that's where the sprite types end
	{
		if (av == spriteTypeList[i])
			return true;
	}
	return false;
}

bool DataSet::isvalidSpriteParameter(std::string sParameter)
{
	for (int i = 0; i < spriteParameterList.size(); i++)
	{
		if (sParameter == spriteParameterList[i])
		{
			return true;
		}
	}
	return false;
}

bool DataSet::isValidColor(std::string color)
{
	for (int i = 0; i < colorList.size(); i++)
	{
		if (color == colorList[i])
		{
			return true;
		}
	}
	return false;
}

bool DataSet::isValidInteractionType(std::string iType)
{
	for (int i = 0; i < interactionTypeList.size(); i++)
	{
		if (iType == interactionTypeList[i])
		{
			return true;
		}
	}
	return false;
}

bool DataSet::isValidInteractionParameter(std::string iParam)
{
	for (int i = 0; i < interactionParametersList.size(); i++)
	{
		if (iParam == interactionParametersList[i])
		{
			return true;
		}
	}
	return false;
}

bool DataSet::isValidTerminationType(std::string tType)
{
	for (int i = 0; i < terminationTypeList.size(); i++)
	{
		if (tType == terminationTypeList[i])
		{
			return true;
		}
	}
	return false;
}

bool DataSet::isValidTerminationParameter(std::string tParam)
{
	for (int i = 0; i < terminationParameterList.size(); i++)
	{
		if (tParam == terminationParameterList[i])
		{
			return true;
		}
	}
	return false;
}
