#include "InspectorTerminationSet.h"



InspectorTerminationSet::InspectorTerminationSet()
{
	vector<string> options = { "one", "two", "three", "four" };
	type = new ofxDatGuiDropdown("Type",options);
	value = new ofxDatGuiTextInput("Value");

	type->setPosition(100,200);
	value->setPosition(100,250);
}


InspectorTerminationSet::~InspectorTerminationSet()
{
}

void InspectorTerminationSet::draw() {
	ofSetColor(255);
	type->draw();
	value->draw();
}

void InspectorTerminationSet::update() {
	type->update();
	value->update();
}

void InspectorTerminationSet::onButtonEvent(ofxDatGuiButtonEvent e) {

}

void InspectorTerminationSet::onTextInputEvent(ofxDatGuiTextInputEvent e) {


}

void InspectorTerminationSet::onDropdownEvent(ofxDatGuiDropdownEvent e) {


}