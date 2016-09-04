#include "MapCharacter.h"



MapCharacter::MapCharacter()
{
}

MapCharacter::MapCharacter(char newC, std::vector<std::string> newS)
{
	mapChar = newC;
	sprites = newS;
}


MapCharacter::~MapCharacter()
{
}

char MapCharacter::getMapChar()
{
	return mapChar;
}

void MapCharacter::setMapChar(char newC)
{
	mapChar = newC;
}

std::vector<std::string> MapCharacter::getAssociatedSprites()
{
	return sprites;
}

void MapCharacter::setAssociatedSprites(std::vector<std::string> newAssSpriteList)
{
	sprites = newAssSpriteList;
}

bool MapCharacter::addAssociatedSprite(std::string newSprite)
{
	//goes through list, if it doesn't exist yet in there, add it and return true, otherwise returns false
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i] == newSprite)
			return false;
	}
	//not in list, so can add
	sprites.push_back(newSprite);
	return true;
}

bool MapCharacter::modifyAssociatedSprite(int spriteIndex, std::string newSprite)
{
	//if index given is too big, return false
	if (spriteIndex >= sprites.size())
		return false;
	//otherwise, modify sprite
	sprites[spriteIndex] = newSprite;
	return true;
}

bool MapCharacter::deleteAssociatedSprite(std::string spriteToDelete)
{
	//goes through list until it finds sprite, deletes it; returns false if it does not find the sprite
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i] == spriteToDelete)
		{
			sprites.erase(sprites.begin() + i);
			return true;
		}

	}
	//didn't find sprite
	return false;
}

bool MapCharacter::deleteAssociatedSprite(int spriteIndex)
{
	//if position given is too big...
	if(spriteIndex>=sprites.size())
		return false;
	//else, delete sprite at position given
	sprites.erase(sprites.begin() + spriteIndex);
	return true;
}

void MapCharacter::operator=(MapCharacter mc)
{
	this->mapChar = mc.mapChar;
	this->sprites = mc.sprites;
}

bool MapCharacter::operator==(MapCharacter mc)
{
	return (this->mapChar == mc.mapChar && this->sprites == mc.sprites);
}
