#pragma once
#include "ofmain.h"
#include "InspectorTerminationSet.h"

class Inspector
{
public:
	Inspector();
	~Inspector();

	void draw();
	void update();
	void mousePressed(int x, int y);

	ofTrueTypeFont font;

	int tab = 1; // 0 = sprite,  1 = termination, 2 = interaction

	InspectorTerminationSet TerminationSet;
};

