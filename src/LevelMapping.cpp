#include "LevelMapping.h"
#include <iostream>


LevelMapping::LevelMapping()
{
}

LevelMapping::LevelMapping(int width, int height)
{
	this->width = width;
	this->height = height;
}


LevelMapping::~LevelMapping()
{
}

std::vector<MapCharacter> LevelMapping::getCharacterList()
{
	return characters;
}

void LevelMapping::setCharacterList(std::vector<MapCharacter> objList)
{
	characters = objList;
}

bool LevelMapping::characterIsInList(char characterToCheck)
{
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i].getMapChar() == characterToCheck)
		{
			//means it's in list, returns true
			return true;
		}

	}
	//gone through whole list, didn't find it
	return false;
}

bool LevelMapping::addCharacterToList(MapCharacter newChar)
{
	//goes through list, checks if character doesn't exist already, if it does return false
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i] == newChar)
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
		if (characters[i].getMapChar() == newCharacter)
			return false;//already exists, can't add
	}
	//if it got to here, doesn't exist yet, can add to list
	MapCharacter newChar(newCharacter, newSprites);
	characters.push_back(newChar);
	return true;
}

bool LevelMapping::deleteCharacterFromList(char charToDelete)
{
	//goes through list, checks if character doesn't exist already, if it does delete and return true
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i].getMapChar() == charToDelete)
		{
			characters.erase(characters.begin() + i);
			return true;//delete succcessfully
		}
	}
	//if it got to here, doesn't exist in list, return false
	return false;
}

bool LevelMapping::deleteCharacterFromList(int charIndex)
{
	//check if index is valid
	if(charIndex>=characters.size())
		return false;
	//delete character by its index
	characters.erase(characters.begin() + charIndex);
	return true;
}



bool LevelMapping::deleteCharacterFromList(MapCharacter charToDelete)
{
	//goes through list, checks if character doesn't exist already, if it does delete and return true
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i] == charToDelete)
		{
			characters.erase(characters.begin() + i);
			return true;//delete succcessfully
		}
	}
	//if it got to here, doesn't exist in list, return false
	return false;
}

bool LevelMapping::modifyWholeObj(int objIndex, MapCharacter newMapChar)
{
	if(objIndex>=characters.size())
		return false;
	characters[objIndex] = newMapChar;
	return true;
}

bool LevelMapping::modifyCharacterFromObj(int objIndex, char newChar)
{
	//if objIndex is out of bounds, return false
	if (objIndex >= characters.size())
		return false;
	//creates a new mapCharacter, substitutes mapCharacter at position objIndex for this new one
	MapCharacter newMapChar(newChar, characters[objIndex].getAssociatedSprites());
	characters[objIndex] = newMapChar;
	return true;
}

bool LevelMapping::addSpriteToObj(int objIndex, std::string newSprite)
{
	//if objIndex is out of bounds, return false
	if (objIndex >= characters.size())
		return false;
	//creates a new mapChar, adds sprite, substitutes old mapChar for new one
	MapCharacter newMapChar;
	newMapChar = characters[objIndex];
	newMapChar.addAssociatedSprite(newSprite);
	characters[objIndex] = newMapChar;
	return true;
}

bool LevelMapping::deleteSpriteFromObj(int objIndex, std::string spriteToDelete)
{
	//goes through object's sprite list, see if the sprite to be deleted is there
	MapCharacter newMC = characters[objIndex];
	if (newMC.deleteAssociatedSprite(spriteToDelete))
	{
		characters[objIndex] = newMC;
		return true;
	}
	return false;
}

bool LevelMapping::deleteSpriteFromObj(int objIndex, int spriteIndex)
{
	//goes through object's sprite list, see if the sprite to be deleted is there
	MapCharacter newMC = characters[objIndex];
	if (newMC.deleteAssociatedSprite(spriteIndex))
	{
		characters[objIndex] = newMC;
		return true;
	}
	return false;
}

bool LevelMapping::isValidMapLine(std::string line)
{
	bool isInList = false;
	//std::cout << "analyzing line " << line << std::endl;
	//heavy operation, O(mn) as far as I noticed, but what other way is there?
	for (int i = 0; i < line.size(); i++)
	{
		//apparently, 'w' and ' ' are hard coded in the language..? If so, hard code these as well...
		if (line[i] == 'w' || line[i] == ' ')
			continue;

		//checks every character of the string against 
		for (int j = 0; j < characters.size(); j++)
		{
			//std::cout << " against " << characters[j].getMapChar() << std::endl;
			//if character found, turn isInList bool to true, break from inner for
			if (line[i] == characters[j].getMapChar())
			{
				isInList = true;
				break;
			}
		}
		//after checking character against all(or less) of the map characters, check it it had a hit.
		if (isInList)
		{
			isInList = false;
			continue;
		}
		else
		{
			//didn't find current character in list, returns false
			return false;
		}
	}
	//if it got here, all characters are ok
	return true;
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

void LevelMapping::setMap(std::vector<std::string> newMap)
{
	//erases current map and saves a new one
	clearMap();
	map = newMap;
}

std::vector<std::string> LevelMapping::getMap()
{
	return map;
}

bool LevelMapping::modifyMapLine(int line, std::string newMapLine)
{
	//checks if the new line has the acceptable size, and if the position to be changed is accepable
	if(line>height || newMapLine.size() >= width)
		return false;
	//otherwise, replaces line with new line
	map[line - 1] = newMapLine;
	return true;
}

void LevelMapping::clearMap()
{
	map.clear();
}



void LevelMapping::resizeMap(int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
}
