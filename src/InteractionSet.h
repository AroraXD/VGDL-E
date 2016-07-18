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
	std::vector<std::string> interactionTypeList = {"killSprite", "killIfHasMore","killIfHasLess","killFromAbove","killIfOtherHasMore","transformToSingleton", //0-5, KILL category
													"spawnBehind","spawnIfHasMore","spawnIfHasLess","cloneSprite","transformTo","updateSpawnType","removeScore",//6-12, SPAWN category
													"stepBack","undoAll",//13-14, UNDO category
													"flipDirection","reverseDirection","attractGaze",//15-17, DIRECTION category
													"turnAround","wrapAround","teleportToExit","pullWithIt","bounceForward",//18-22,MOVE category
													"collectResource","changeResource"//23-24, RESOURCE category
													};


	std::vector<std::string> interactionParametersList = {"resource", "limit","stype","stype_other","spawnPoint","value"};
};

