/*
 * Sprite.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: BConfessor
 */

#include "Sprite.h"

//Sprite::Sprite() {
//	// TODO Auto-generated constructor stub
//
//}

Sprite::Sprite()
{
}

Sprite::Sprite(std::string newName, std::string stype, bool hasParent, std::string parent)
{
	name = newName;
	spriteType = stype;
	this->hasParent = hasParent;
	this->parent = parent;
}

Sprite::Sprite(std::string newName, std::string stype, std::vector<Parameter> paramList, bool hasParent, std::string parent)
{
	name = newName;
	spriteType = stype;
	parameterList = paramList;
	this->hasParent = hasParent;
	this->parent = parent;
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

std::vector<Parameter> Sprite::getSpriteParameters()
{
	return parameterList;
}

void Sprite::addParameter(Parameter newParameter)
{
	parameterList.push_back(newParameter);
}

std::string Sprite::getParent()
{
	return parent;
}

void Sprite::setParent(std::string newParent)
{
	parent = newParent;
}

bool Sprite::spriteHasParent()
{
	return hasParent;
}

bool Sprite::operator==(Sprite s)
{
	return (this->getName() == s.getName() && this->getParent() == s.getParent() && haveSameParameterList(*this, s));
}

void Sprite::operator=(Sprite s)
{
	this->name = s.getName();
	this->parent = s.getParent();
	this->hasParent = s.spriteHasParent();
	this->spriteType = s.getSpriteType();

	this->parameterList = s.getParameterList();
}

bool Sprite::haveSameParameterList(Sprite s1, Sprite s2)
{
	//if they're not even the same size, goes straight to false
	if (s1.getParameterList().size() != s2.getParameterList().size())
		return false;
	else//same size, so we check item by item
	{
		for (int i = 0; i < s1.getParameterList().size(); i++)
		{
			if (!(s1.getParameterList()[i] == s2.getParameterList()[i]))//diff name or value, ergo diff parameter
			{
				return false;
			}

		}

	}
	//after all tests, if it got here, means it has the same parameter list
	return true;
}

