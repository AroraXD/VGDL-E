#pragma once

#include "Interaction.h"
#include <vector>

class InteractionSet
{
public:
	InteractionSet();
	InteractionSet(std::vector<Interaction> intList);//most likely won't use this, as I might just add interactions one by one
	~InteractionSet();

	std::vector<std::string> getInteractionTypeList();//gets interaction type list; used for drop down menus in GUI
	std::vector<std::string> getInteractionParametersList();//gets possible parameters list; used for drop down menus in GUI

	std::vector<Interaction> getInteractionList();//returns the existing list of interactions
	void setInteractionList(std::vector<Interaction> newIntList);//sets a whole interaction list; probably not going to be used
	void addInteraction(Interaction newInteraction);//adds new interaction to list

	//deletes Interaction from the Interaction list; has to check all, so O(n), but list will be small, so it should be fine
	void deleteInteraction(Interaction erasedInteraction);

private:
	std::vector<Interaction> interactionList;
	std::vector<std::string> interactionTypeList = {"killSprite", "killIfHasMore","killIfHasLess","killFromAbove","killIfOtherHasMore","transformToSingleton", //0-5, KILL category
													"spawnBehind","spawnIfHasMore","spawnIfHasLess","cloneSprite","transformTo","updateSpawnType","removeScore",//6-12, SPAWN category
													"stepBack","undoAll",//13-14, UNDO category
													"flipDirection","reverseDirection","attractGaze",//15-17, DIRECTION category
													"turnAround","wrapAround","teleportToExit","pullWithIt","bounceForward",//18-22,MOVE category
													"collectResource","changeResource"//23-24, RESOURCE category
													};


	std::vector<std::string> interactionParametersList = {"resource", "limit","stype","stype_other","spawnPoint","value"};
};

