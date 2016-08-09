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

	void workWithVGDLCreator(VGDLParser* vgdl, SpriteSet* ss, InteractionSet* is, TerminationSet* ts);
	void loadVGDLFile(std::ofstream fileToRead);
	//methods for each of the possible options when choosing one of the 3 main categories(not working with level mapping now

	//Option 1: Add methods, gets all the possible values and parameters of a Sprite/Termination/Interaction, and at the end saves a new obj to the list
	void addSpriteInList(SpriteSet* ss);
	void addParameter(Sprite* s);
	void addTerminationInList(TerminationSet* ts);
	void addParameter(Termination* t);
	void addInteractionInList(InteractionSet* is);
	void addParameter(Interaction* i);

	//Option 2: Modify methods, shows user a list of objects, asks them to pick one, modify all atributes to their heart's content
	void modifySprite(SpriteSet* ss);
	void changeSpriteParent(Sprite* s, SpriteSet* ss);
	void modifyTermination(TerminationSet* ts);
	void modifyInteraction(InteractionSet* is);


	//Option 2: Delete methods, deletes objects based on name/position in list
	void deleteSpriteFromList(SpriteSet* ss);
	void deleteTerminationFromList(TerminationSet* ts);
	void deleteInteractionFromList(InteractionSet* is);



	//Option 4: Display methods, gets the list of sprites/terminations/interactions and shows it in a decent way to the user
	void showSprite(SpriteSet* ss, int index);//shows sprite of index i in spriteList
	void showSprite(Sprite* s);//displays selected sprite on screen
	void showSpriteList(SpriteSet* ss);
	void showSpriteParentTree(SpriteSet* ss);//shows children of spriteList
	void showRootSprites(SpriteSet* ss);
	void showSpriteAndChildren(SpriteSet* ss, Sprite* s);//shows children of s

	void showTermination(TerminationSet* ts, int index);
	void showTermination(Termination t);
	void showTerminationList(TerminationSet* ts);
	void showInteraction(InteractionSet* is, int index);
	void showInteraction(Interaction i);
	void showInteractionList(InteractionSet* is);

	//parameter-handling methods
	void showParameters(Sprite* s);
	void showParameters(Termination t);
	void showParameters(Interaction i);

private:


};

