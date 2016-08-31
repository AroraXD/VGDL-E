#include "LevelMapping.h"



LevelMapping::LevelMapping()
{
}


LevelMapping::~LevelMapping()
{
}

std::vector<Object> LevelMapping::getCharacterList()
{
	return characters;
}

void LevelMapping::setCharacterList(std::vector<Object> objList)
{
	characters = objList;
}

bool LevelMapping::addCharacterToList(Object newChar)
{
	//goes through list, checks if character doesn't exist already, if it does return false
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i].mapCharacter == newChar.mapCharacter)
			return false;//already exists, can't add
	}
	//if it got to here, doesn't exist yet, can add to list
	characters.push_back(newChar);
	return true;
}

bool LevelMapping::addCharacterToList(char newCharacter, std::vector<std::string> newSprites)
{

	//goes through list, checks if character doesn't exist already, if it does return false
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i].mapCharacter == newCharacter)
			return false;//already exists, can't add
	}
	//if it got to here, doesn't exist yet, can add to list
	Object newChar;
	newChar.mapCharacter = newCharacter;
	newChar.sprites = newSprites;
	characters.push_back(newChar);
	return true;
}

bool LevelMapping::deleteCharacterFromList(char charToDelete)
{
	//goes through list, checks if character doesn't exist already, if it does delete and return true
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i].mapCharacter == charToDelete)
		{
			characters.erase(characters.begin() + i);
			return true;//delete succcessfully
		}
	}
	//if it got to here, doesn't exist in list, return false
	return false;
}

bool LevelMapping::deleteCharacterFromList(Object charToDelete)
{
	//goes through list, checks if character doesn't exist already, if it does delete and return true
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i].mapCharacter == charToDelete.mapCharacter)
		{
			characters.erase(characters.begin() + i);
			return true;//delete succcessfully
		}
	}
	//if it got to here, doesn't exist in list, return false
	return false;
}

int LevelMapping::getWidth()
{
	return width;
}

void LevelMapping::setWidth(int w)
{
	width = w;
}

int LevelMapping::getHeight()
{
	return height;
}

void LevelMapping::setHeight(int h)
{
	height = h;
}
