#include "InteractionSet.h"



InteractionSet::InteractionSet()
{
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
