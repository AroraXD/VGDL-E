#include "Interaction.h"




Interaction::Interaction(std::string spriteName, std::vector<std::string> interactorSpritesList)
{
	interactedSprite = spriteName;
	interactorSprites = interactorSpritesList;
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

