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

	void workWithSpriteSet(SpriteSet ss);
	void workWithInteractionSet(InteractionSet is);
	void workWithTerminationSet(TerminationSet ts);



};

