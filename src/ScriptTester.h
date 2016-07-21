#pragma once

#include "InteractionSet.h"
#include "SpriteSet.h"
#include "TerminationSet.h"
#include "VGDLParser.h"



class ScriptTester
{
public:
	ScriptTester();
	~ScriptTester();

	void runScriptTest(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet);


	//needs to be pointers because they need to be modified 
	void workWithSpriteSet(SpriteSet* ss);
	void workWithInteractionSet(InteractionSet* is);
	void workWithTerminationSet(TerminationSet* ts);

	void workWithVGDLCreator(VGDLParser* vgdl);

	//methods for each of the possible options when choosing one of the 3 main categories(not working with level mapping now

	//Option 1: Add methods, gets all the possible values and parameters of a Sprite/Termination/Interaction, and at the end saves a new obj to the list
	void addSpriteInList(SpriteSet* ss);
	void addParameter(Sprite* s);
	void addTerminationInList(TerminationSet* ts);
	void addParameter(Termination* t);
	void addInteractionInList(InteractionSet* is);
	void addParameter(Interaction* i);

	//Option 2: Delete methods, deletes objects based on name/position in list
	void deleteSpriteFromList(SpriteSet* ss);
	void deleteTerminationFromList(TerminationSet* ts);
	void deleteInteractionFromList(InteractionSet* is);

	//Option 3: Display methods, gets the list of sprites/terminations/interactions and shows it in a decent way to the user
	void showSpriteList(SpriteSet* ss);
	void showTerminationList(TerminationSet* ts);
	void showInteractionList(InteractionSet* is);

};

