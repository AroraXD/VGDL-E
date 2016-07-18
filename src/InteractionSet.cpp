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
