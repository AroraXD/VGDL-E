#include "Inspector.h"



Inspector::Inspector()
{
	font.loadFont("playtime.ttf", 16);
	//Creates GUI for map dimensions holding
	mapDimensionGUI = new ofxDatGui(900, 20);
	mapX = mapDimensionGUI->addSlider("X size: ", 1, 15);
	mapY = mapDimensionGUI->addSlider("Y size: ", 1, 15);

	//Creates GUI for the save and load buttons
	saveLoadGUI = new ofxDatGui(600, 20);
	save=saveLoadGUI->addButton("Save Script");
	load=saveLoadGUI->addButton("Load Script");
	run=saveLoadGUI->addButton("Run");

}


Inspector::~Inspector()
{
}

void Inspector::update()
{
	if (tab == 0) {

	}
	else if (tab == 1) {
		TerminationSet.update();
	}
	else if (tab == 2) {

	}

}

void Inspector::draw()
{
	ofSetColor(200, 200);
	ofDrawRectangle(ofGetWidth()*0.01, ofGetHeight()*0.15, ofGetWidth()*0.15, ofGetHeight()*0.05);//tab 0
	ofSetColor(255);
	font.drawString("SpriteSet", ofGetWidth()*0.04, ofGetHeight()*0.175);

	ofSetColor(220, 200);
	ofDrawRectangle(ofGetWidth()*0.16, ofGetHeight()*0.15, ofGetWidth()*0.15, ofGetHeight()*0.05);//tab 1
	ofSetColor(255);
	font.drawString("TerminationSet", ofGetWidth()*0.18, ofGetHeight()*0.175);

	ofSetColor(180, 200);
	ofDrawRectangle(ofGetWidth()*0.31, ofGetHeight()*0.15, ofGetWidth()*0.15, ofGetHeight()*0.05);//tab 2
	ofSetColor(255);
	font.drawString("InteractionSet", ofGetWidth()*0.33, ofGetHeight()*0.175);

	if (tab == 0)
	{
		ofSetColor(200, 200);
		ofDrawRectangle(ofGetWidth()*0.01, ofGetHeight()*0.2, ofGetWidth()*0.45, ofGetHeight()*0.55);
	}
	else if (tab == 1)
	{
		ofSetColor(220, 200);
		ofDrawRectangle(ofGetWidth()*0.01, ofGetHeight()*0.2, ofGetWidth()*0.45, ofGetHeight()*0.55);
		TerminationSet.draw();
	}
	else if (tab == 2)
	{
		ofSetColor(180, 200);
		ofDrawRectangle(ofGetWidth()*0.01, ofGetHeight()*0.2, ofGetWidth()*0.45, ofGetHeight()*0.55);
	}
}

void Inspector::mousePressed(int x, int y)
{
	if (x > ofGetWidth()*0.01 && x < ofGetWidth()*0.16 && y > ofGetHeight()*0.15 && y < ofGetHeight()*0.2)
	{
		tab = 0;
	}
	else if (x > ofGetWidth()*0.16 && x < ofGetWidth()*0.31 && y > ofGetHeight()*0.15 && y < ofGetHeight()*0.2)
	{
		tab = 1;
	}
	else if (x > ofGetWidth()*0.31 && x < ofGetWidth()*0.46 && y > ofGetHeight()*0.15 && y < ofGetHeight()*0.2)
	{
		tab = 2;
	}
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
	cout << e.target->getLabel() << " was clicked!" << endl;
}