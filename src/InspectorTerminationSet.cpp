#include "InspectorTerminationSet.h"
#include <iostream>


InspectorTerminationSet::InspectorTerminationSet()
{
	type = new ofxDatGuiDropdown("Type",dt.getTerminationTypeList());
	value = new ofxDatGuiTextInput("Value");

	//starts with one termination, always(should I...?)
	currentTermination = 1;
	numberOfTerminations = 1;

	numberOfParametersLoaded = 4;//for now, load no parameters

	int j = 280;
	for (int i = 0; i < 4; i++)//Creates 4 parameter values and types. They will only show depending on what's chosen in the dropdown
	{
		ofxDatGuiDropdown* newType = new ofxDatGuiDropdown("Type", dt.getTerminationParameterList());
		newType->setPosition(100, j);
		j += 30;
		paramType.push_back(newType);

		ofxDatGuiTextInput* newValue = new ofxDatGuiTextInput("Value");
		newValue->setPosition(100, j);
		j += 60;
		paramValue.push_back(newValue);

	}

	//Setting up position of Termination Type and Value
	type->setPosition(100, 200);
	value->setPosition(100, 220);
}

InspectorTerminationSet::InspectorTerminationSet(TerminationSet * ts)
{
	this->ts = ts;
	type = new ofxDatGuiDropdown("Type", dt.getTerminationTypeList());
	value = new ofxDatGuiTextInput("Value");

	//starts with one termination, always(should I...?)
	currentTermination = 1;
	numberOfTerminations = 1;
	numberOfParametersLoaded = 4;//for now, load no parameters

	int j = 300;
	for (int i = 0; i < 4; i++)//Creates 4 parameter values and types. They will only show depending on what's chosen in the dropdown
	{
		ofxDatGuiDropdown* newType = new ofxDatGuiDropdown("Type", dt.getTerminationParameterList());
		newType->setPosition(100, j);
		j += 30;
		paramType.push_back(newType);

		ofxDatGuiTextInput* newValue = new ofxDatGuiTextInput("Value");
		newValue->setPosition(100, j);
		j += 60;
		paramValue.push_back(newValue);

	}

	//Setting up position of Termination Type and Value
	type->setPosition(100, 200);
	value->setPosition(100, 220);


}


InspectorTerminationSet::~InspectorTerminationSet()
{
}

void InspectorTerminationSet::draw() {
	ofSetColor(255);

	//ALWAYS draw them from bottom to top, so lower objects won't get in the way of the dropdown menus being ....dropped down
	for (int i = numberOfParametersLoaded-1; i > -1; i--)
	{
		paramValue[i]->draw();
		paramType[i]->draw();
	}
	value->draw();
	type->draw();

}

void InspectorTerminationSet::update() {
	value->update();
	type->update();

	for (int i = 0; i < numberOfParametersLoaded; i++)
	{
		paramValue[i]->update();
		paramType[i]->update();
	}
}

void InspectorTerminationSet::onButtonEvent(ofxDatGuiButtonEvent e) {

}

void InspectorTerminationSet::onTextInputEvent(ofxDatGuiTextInputEvent e) {


}

void InspectorTerminationSet::onDropdownEvent(ofxDatGuiDropdownEvent e) {


}

void InspectorTerminationSet::addNewTermination()
{
	//Increases number of Terminations, changes to new termination
	numberOfTerminations++;
	clearInputs();//loads empty termination
}

void InspectorTerminationSet::clearInputs()
{
	//TODO: Clears inputs of all input fields and dropdown lists
}

void InspectorTerminationSet::loadTermination(Termination t)
{
}

void InspectorTerminationSet::loadNextTermination()
{
	if (currentTermination >= numberOfTerminations)
	{
		//go to first one
		currentTermination = 1;//since it goes from 1-n
		loadTermination(ts->getTerminationList()[0]);
	}
	else
	{
		currentTermination++;
		loadTermination(ts->getTerminationList()[currentTermination - 1]);
	}
}

void InspectorTerminationSet::loadPreviousTermination()
{
	if (currentTermination <= 1)
	{
		//go to last one
		currentTermination = numberOfTerminations;//since it goes from 1-n
		loadTermination(ts->getTerminationList()[currentTermination-1]);
	}
	else
	{
		currentTermination--;
		loadTermination(ts->getTerminationList()[currentTermination - 1]);
	}
}

int InspectorTerminationSet::getCurrentTermination()
{
	return currentTermination;
}

void InspectorTerminationSet::setCurrentTermination(int t)
{
	currentTermination = t;
}

int InspectorTerminationSet::getNumberOfTerminations()
{
	return numberOfTerminations;
}

void InspectorTerminationSet::setNumberOfTerminations(int t)
{
	numberOfTerminations = t;
}
