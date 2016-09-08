#pragma once

#include "InteractionSet.h"
#include "SpriteSet.h"
#include "TerminationSet.h"
#include "LevelMapping.h"
#include "GlobalGameParameters.h"
#include "VGDLParser.h"



class ScriptTester
{
public:
	ScriptTester();
	~ScriptTester();

	void runScriptTest(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet, LevelMapping levelMapping, GlobalGameParameters globalGameParameters);


	//needs to be pointers because they need to be modified 
	void workWithSpriteSet(SpriteSet* ss);
	void workWithInteractionSet(InteractionSet* is);
	void workWithTerminationSet(TerminationSet* ts);
	void workWithLevelMapping(LevelMapping* lm);
	void workWithGlobalGameParameters(GlobalGameParameters* ggp);

	void workWithVGDLCreator(VGDLParser* vgdl, SpriteSet* ss, InteractionSet* is, TerminationSet* ts, LevelMapping* lm, GlobalGameParameters* ggp);
	void loadVGDLFile(std::ofstream fileToRead);
	//methods for each of the possible options when choosing one of the 5 main categories

	//Option 1: Add methods, gets all the possible values and parameters of a Sprite/Termination/Interaction, and at the end saves a new obj to the list
	void addSpriteInList(SpriteSet* ss);
	void addParameter(Sprite* s);
	void addTerminationInList(TerminationSet* ts);
	void addParameter(Termination* t);
	void addInteractionInList(InteractionSet* is);
	void addParameter(Interaction* i);
	void addMapCharacterInList(LevelMapping* lm);
	void addGlobalParameter(GlobalGameParameters* ggp);
	void addMap(LevelMapping* lm);
	void getMapFromLevelEditor();//gets the information from the level editor, dunno how yet


	//Option 2: Modify methods, shows user a list of objects, asks them to pick one, modify all atributes to their heart's content
	void modifySprite(SpriteSet* ss);
	void changeSpriteParent(Sprite* s, SpriteSet* ss);
	void modifyTermination(TerminationSet* ts);
	void modifyInteraction(InteractionSet* is);
	void modifyMapCharacter(LevelMapping* lm);
	void modifyGlobalParameter(GlobalGameParameters* ggp);


	//Option 2: Delete methods, deletes objects based on name/position in list
	void deleteSpriteFromList(SpriteSet* ss);
	void deleteTerminationFromList(TerminationSet* ts);
	void deleteInteractionFromList(InteractionSet* is);
	void deleteMapCharacterFromList(LevelMapping* lm);
	void deleteGlobalParameters(GlobalGameParameters* ggp);


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
	void showMapCharacter(MapCharacter mc);
	void showLevelMapping(LevelMapping* lm);
	void showMap(LevelMapping* lm);


	//parameter-handling methods
	void showParameters(Sprite* s);
	void showParameters(Termination t);
	void showParameters(Interaction i);
	void showGlobalParameters(GlobalGameParameters* ggp);

private:


};

