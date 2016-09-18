#pragma once
#include "ofxDatGui.h"

class InspectorTerminationSet
{
public:
	InspectorTerminationSet();
	~InspectorTerminationSet();

	void draw();
	void update();


	//ofxDatGuiButton* button;
	//ofxDatGuiButton* toggle;
	
	ofxDatGuiDropdown* type;
	ofxDatGuiTextInput* value;

	
	void onButtonEvent(ofxDatGuiButtonEvent e);
	void onTextInputEvent(ofxDatGuiTextInputEvent e);
	void onDropdownEvent(ofxDatGuiDropdownEvent e);

};


