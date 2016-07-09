#pragma once

#include <vector>

class InteractionSet
{
public:
	InteractionSet();
	~InteractionSet();

	std::vector<std::string> getInteractionTypeList();
	std::vector<std::string> getInteractionParametersList();


private:
	//std::vector<Interaction> interactionList;
	std::vector<std::string> interactionTypeList = {};
	std::vector<std::string> interactionParametersList = {};
};

