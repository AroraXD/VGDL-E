#pragma once

#include "Interaction.h"
#include <vector>

class InteractionSet
{
public:
	InteractionSet();
	InteractionSet(std::vector<Interaction> intList);//most likely won't use this, as I might just add interactions one by one
	~InteractionSet();


	std::vector<Interaction> getInteractionList();//returns the existing list of interactions
	void setInteractionList(std::vector<Interaction> newIntList);//sets a whole interaction list; probably not going to be used
	void addInteraction(Interaction newInteraction);//adds new interaction to list

	//deletes Interaction from the Interaction list; has to check all, so O(n), but list will be small, so it should be fine
	bool deleteInteraction(Interaction erasedInteraction);
	bool deleteInteraction(std::string interactedSpriteName);//deletes interaction by getting the first case where the interacted sprite = parameter
	bool deleteInteraction(int index);//deletes interaction based on its position in the list

	//puts newInteraction in InteractionList at the position index
	void modifyInteraction(Interaction newInteraction, int index);


private:
	std::vector<Interaction> interactionList;

};

