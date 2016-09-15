#include "Manager.h"

#include <ctype.h>


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

void Manager::capitalizeInitial(std::string input)
{
	input[0] = toupper(input[0]);
}

void Manager::decapitalizeInitial(std::string input)
{
	input[0] = tolower(input[0]);
}

bool Manager::isAlphabetic(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		//if any chars are non-alpha, return false
		if (!isalpha(input[i]))
		{
			return false;
		}
	}
	return true;
}

std::vector<std::string> Manager::getSpritesFromImages(std::vector<std::string> images)
{
	return std::vector<std::string>();
}

std::vector<char> Manager::getCharsFromSprites(std::vector<std::string> sprites)
{
	return std::vector<char>();
}

bool Manager::buildASCIIMapFromImageMap(std::vector<draggableSprite> mapImages)
{
	//TODO: Implement
	return false;
}


