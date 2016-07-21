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

	//gets the list of sprites/terminations/interactions and shows it in a decent way to the user
	void showSpriteList(SpriteSet* ss);
	void showTerminationList(TerminationSet* ts);
	void showInteractionList(InteractionSet* is);

};

