#include "Interaction.h"




Interaction::Interaction(std::string spriteName, std::vector<std::string> interactorSpritesList)
{
	interactedSprite = spriteName;
	interactorSprites = interactorSpritesList;
}

Interaction::Interaction(std::string spriteName, std::vector<std::string> interactorSpritesList, std::string consequence)
{
	interactedSprite = spriteName;
	interactorSprites = interactorSpritesList;
	interactionType = consequence;
}

Interaction::Interaction(std::string spriteName, std::vector<std::string> interactorSpritesList, std::vector<Parameter> interactionParameterList)
{
	interactedSprite = spriteName;
	interactorSprites = interactorSpritesList;
	parameterList = interactionParameterList;
}

Interaction::~Interaction()
{
}


std::string Interaction::getInteractedSprite()
{
	return interactedSprite;
}

void Interaction::setInteractedSprite(std::string newInteractedSprite)
{
	interactedSprite = newInteractedSprite;
}

std::string Interaction::getInteractionType()
{
	return interactionType;
}

void Interaction::setInteractionType(std::string newInteractionType)
{
	interactionType = newInteractionType;
}

std::vector<std::string> Interaction::getInteractorSprites()
{
	return interactorSprites;
}

void Interaction::setInteractorSprites(std::vector<std::string> newInteractorList)
{
	interactorSprites = newInteractorList;
}

void Interaction::addNewInteractorSprite(std::string newInteractorSprite)
{
	interactorSprites.push_back(newInteractorSprite);
}

bool Interaction::operator==(Interaction i)
{
	return (this->getInteractedSprite() == i.getInteractedSprite() &&
			haveSameParameterList(*this, i) && haveSameInteractorSprites(*this, i) &&
			this->getInteractionType() == i.getInteractionType());
}

void Interaction::operator=(Interaction i)
{
	this->interactedSprite = i.getInteractedSprite();
	this->interactorSprites = i.getInteractorSprites();
	this->interactionType = i.getInteractionType();
	this->parameterList = i.getParameterList();
}

bool Interaction::haveSameInteractorSprites(Interaction i1, Interaction i2)
{
	return i1==i2;
}

bool Interaction::haveSameParameterList(Interaction i1, Interaction i2)
{
	//if they're not even the same size, goes straight to false
	if (i1.getParameterList().size() != i2.getParameterList().size())
		return false;
	else//same size, so we check item by item
	{
		for (int i = 0; i < i1.getParameterList().size(); i++)
		{
			if (!(i1.getParameterList()[i] == i2.getParameterList()[i]))//diff name or value, ergo diff parameter
			{
				return false;
			}

		}

	}
	//after all tests, if it got here, means it has the same parameter list
	return true;
}

