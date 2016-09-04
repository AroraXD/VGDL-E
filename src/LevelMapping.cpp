#include "LevelMapping.h"



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

void LevelMapping::createMap()
{
}

void LevelMapping::resizeMap(int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
}
