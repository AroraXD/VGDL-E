/*
 * SpriteSet.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: BConfessor
 */

#include "SpriteSet.h"

SpriteSet::SpriteSet() {
	// TODO Auto-generated constructor stub

}

SpriteSet::~SpriteSet() {
	// TODO Auto-generated destructor stub
}

std::vector<Sprite> SpriteSet::getSpriteList()
{
	return spriteList;
}

void SpriteSet::addSprite(Sprite newSprite)
{
	spriteList.push_back(newSprite);
}

bool SpriteSet::deleteSprite(Sprite erasedSprite)
{
	//goes through the sprite list(O(n), I know) and delete the correct sprite
	for (int i = 0; i < spriteList.size(); i++)
	{
		if (spriteList[i] == erasedSprite)
		{
			//delete this sprite
			spriteList.erase(spriteList.begin()+i);
			return true;
		}
	}
	return true;
}

bool SpriteSet::deleteSprite(std::string spriteName)
{
	//goes through the sprite list(O(n), I know) and delete the correct sprite
	for (int i = 0; i < spriteList.size(); i++)
	{
		if (spriteList[i].getName() == spriteName)
		{
			//delete this sprite
			spriteList.erase(spriteList.begin() + i);
			return true;
		}
	}

	return false;
}

bool SpriteSet::deleteSprite(int index)
{
	if (index <= spriteList.size() - 1)
	{
		spriteList.erase(spriteList.begin() + index);
		return true;
	}
	return false;
}


std::vector<std::string> SpriteSet::getSpriteTypeList()
{
	return spriteTypeList;
}

std::vector<std::string> SpriteSet::getColorList()
{
	return colorList;
}

std::vector<std::string> SpriteSet::getSpriteParameterList()
{
	return spriteParameterList;
}

