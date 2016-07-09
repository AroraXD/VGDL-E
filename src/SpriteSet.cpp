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

std::list<Sprite> SpriteSet::getSpriteList()
{
	return spriteList;
}

void SpriteSet::addSpriteInList(Sprite newS)
{
	spriteList.push_back(newS);
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

