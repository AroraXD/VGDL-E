#pragma once
#include "ofmain.h"
#include "ofxDatGui.h"
#include "InspectorTerminationSet.h"

class Inspector
{
public:
	Inspector();
	~Inspector();

	void draw();
	void update();
	void mousePressed(int x, int y);


private:

	ofxDatGui* mapDimensionGUI;
	ofxDatGuiSlider* mapX, *mapY;
	ofxDatGui* saveLoadGUI;
	ofxDatGuiButton *save, *load, *run;

	ofTrueTypeFont font;

	int tab = 1; // 0 = sprite,  1 = termination, 2 = interaction

	InspectorTerminationSet TerminationSet;
};

