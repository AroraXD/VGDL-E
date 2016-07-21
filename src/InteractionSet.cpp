#include "InteractionSet.h"



InteractionSet::InteractionSet()
{
}

InteractionSet::InteractionSet(std::vector<Interaction> intList)
{
	interactionList = intList;
}


InteractionSet::~InteractionSet()
{
}

std::vector<std::string> InteractionSet::getInteractionTypeList()
{
	return interactionTypeList;
}

std::vector<std::string> InteractionSet::getInteractionParametersList()
{
	return interactionParametersList;
}

std::vector<Interaction> InteractionSet::getInteractionList()
{
	return interactionList;
}

void InteractionSet::setInteractionList(std::vector<Interaction> newIntList)
{
	interactionList = newIntList;
}

void InteractionSet::addInteraction(Interaction newInteraction)
{
	interactionList.push_back(newInteraction);
}

bool InteractionSet::deleteInteraction(Interaction erasedInteraction)
{
	//goes through the interaction list(O(n), I know) and delete the correct interaction
	for (int i = 0; i < interactionList.size(); i++)
	{
		if (interactionList[i] == erasedInteraction)
		{
			//delete this interaction
			interactionList.erase(interactionList.begin() + i);
			return true;
		}
	}
	//if it didn't find, means interaction didn't exist, return false
	return false;
}

bool InteractionSet::deleteInteraction(std::string interactedSpriteName)
{
	//goes through the interaction list(O(n), I know) and delete the correct interaction
	for (int i = 0; i < interactionList.size(); i++)
	{
		if (interactionList[i].getInteractedSprite() == interactedSpriteName)
		{
			//delete this interaction
			interactionList.erase(interactionList.begin() + i);
			return true;
		}
	}
	return false;//didn't find interaction, didn't delete it
}

bool InteractionSet::deleteInteraction(int index)
{
	if (index <= interactionList.size() - 1)
	{
		interactionList.erase(interactionList.begin() + index);
		return true;
	}
	return false;
}

