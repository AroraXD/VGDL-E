#pragma once
#include "ofmain.h"
#include "ofxDatGui.h"
#include "InspectorTerminationSet.h"

//backend
#include "InteractionSet.h"
#include "SpriteSet.h"
#include "TerminationSet.h"
#include "LevelMapping.h"
#include "GlobalGameParameters.h"
#include "VGDLParser.h"
#include "Manager.h"


/*This class will hold the general non-tab specific buttons, as well as control the tab change
*
*
*/

class Inspector
{
public:
	Inspector();
	~Inspector();

	void draw();
	void update();
	void mousePressed(int x, int y);
	void onButtonEvent(ofxDatGuiButtonEvent e);

	bool saveWasClicked();
	void setSaveClicked(bool b);

	bool loadWasClicked();
	void setLoadClicked(bool b);

	bool runWasClicked();
	void setRunClicked(bool b);


private:


	bool clickedSave = false;
	bool clickedLoad = false;
	bool clickedRun = false;

	ofxDatGui* mapDimensionGUI;
	ofxDatGuiSlider* mapX, *mapY;
	ofxDatGui* saveLoadGUI;
	ofxDatGuiButton *save, *load, *run;





	ofTrueTypeFont font;

	int tab = 1; // 0 = sprite,  1 = termination, 2 = interaction

	InspectorTerminationSet TerminationSet;
};

