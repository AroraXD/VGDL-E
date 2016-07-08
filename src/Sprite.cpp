/*
 * Sprite.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: BConfessor
 */

#include "Sprite.h"

Sprite::Sprite() {
	// TODO Auto-generated constructor stub

}

Sprite::Sprite(std::string newName, std::string stype)
{
	name = newName;
	spriteType = stype;
}

Sprite::Sprite(std::string newName, std::string stype, std::list<SpriteParameter> paramList)
{
	name = newName;
	spriteType = stype;
	parameterList = paramList;
}

Sprite::~Sprite() {
	// TODO Auto-generated destructor stub
	
}

std::string Sprite::getName()
{
	return name;
}

void Sprite::setName(std::string newName)
{
	name = newName;
}

std::string Sprite::getSpriteType()
{
	return spriteType;
}

void Sprite::setSpriteType(std::string newstype)
{
	spriteType = newstype;
}

std::vector<SpriteParameter> Sprite::getSpriteParameters()
{
	return parameterList;
}

void Sprite::addParameter(SpriteParameter newParameter)
{
	parameterList.push_back(newParameter);
}

