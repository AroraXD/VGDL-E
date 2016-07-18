#pragma once

#include "Interaction.h"
#include <vector>

class InteractionSet
{
public:
	InteractionSet();
	InteractionSet(std::vector<Interaction> intList);
	~InteractionSet();

	std::vector<std::string> getInteractionTypeList();
	std::vector<std::string> getInteractionParametersList();

	std::vector<Interaction> getInteractionList();
	void setInteractionList(std::vector<Interaction> newIntList);
	void addInteraction(Interaction newInteraction);

private:
	std::vector<Interaction> interactionList;
	std::vector<std::string> interactionTypeList = {};
	std::vector<std::string> interactionParametersList = {};
};

