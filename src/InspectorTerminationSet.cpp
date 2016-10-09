#include "InspectorTerminationSet.h"
#include <iostream>


InspectorTerminationSet::InspectorTerminationSet()
{


	type = new ofxDatGuiDropdown("Termination Type",dt.getTerminationTypeList());
	type->onDropdownEvent(this, &InspectorTerminationSet::onDropdownEvent);
	
	//starts with one termination, always(should I...?)
	currentTermination = 1;
	numberOfTerminations = 1;

	numberOfParametersLoaded = 4;//for now, load no parameters

	int j = 280;
	for (int i = 0; i < 4; i++)//Creates 4 parameter values and types, and start their events. They will only show depending on what's chosen in the dropdown
	{
		ofxDatGuiDropdown* newType = new ofxDatGuiDropdown("Parameter Type", dt.getTerminationParameterList());
		newType->onDropdownEvent(this, &InspectorTerminationSet::onDropdownEvent);
		newType->setPosition(buttonsX, j);
		j += 30;
		paramType.push_back(newType);

		ofxDatGuiTextInput* newValue = new ofxDatGuiTextInput("Value");
		newValue->onTextInputEvent(this, &InspectorTerminationSet::onTextInputEvent);
		newValue->setPosition(buttonsX, j);
		j += 60;
		paramValue.push_back(newValue);

	}



	//Setting up position of Termination Type and Value
	type->setPosition(buttonsX, 200);
	//value->setPosition(100, 220);
}

InspectorTerminationSet::InspectorTerminationSet(TerminationSet * ts)
{
	this->ts = ts;
	type = new ofxDatGuiDropdown("Termination Type", dt.getTerminationTypeList());
	//value = new ofxDatGuiTextInput("Value");

	//starts with one termination, always(should I...?)
	currentTermination = 1;
	numberOfTerminations = 1;
	numberOfParametersLoaded = 4;//for now, load no parameters

	int j = buttonsY+100;
	for (int i = 0; i < 4; i++)//Creates 4 parameter values and types. They will only show depending on what's chosen in the dropdown
	{
		ofxDatGuiDropdown* newType = new ofxDatGuiDropdown("Parameter Type", dt.getTerminationParameterList());
		newType->setPosition(buttonsX, j);
		j += 30;
		paramType.push_back(newType);

		ofxDatGuiTextInput* newValue = new ofxDatGuiTextInput("Value");
		newValue->setPosition(buttonsX, j);
		j += 60;
		paramValue.push_back(newValue);

	}

	//Setting up position of Termination Type and Value
	type->setPosition(buttonsX, buttonsY);
	//value->setPosition(100, 220);


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
	//value->draw();
	type->draw();

}

void InspectorTerminationSet::update() {
	//value->update();
	type->update();

	for (int i = 0; i < numberOfParametersLoaded; i++)
	{
		paramValue[i]->update();
		paramType[i]->update();
	}
}

void InspectorTerminationSet::onButtonEvent(ofxDatGuiButtonEvent e) {

}

void InspectorTerminationSet::onTextInputEvent(ofxDatGuiTextInputEvent e)
{
	for (int i = 0; i < numberOfParametersLoaded; i++)
	{
		if (e.target == paramValue[i])
		{
			cout << paramValue[i]->getText() << " was written! " << endl;
		}
	}
}

void InspectorTerminationSet::onDropdownEvent(ofxDatGuiDropdownEvent e) 
{
	//if the dropdown clicked is the Termination Type one, it changes the amount of parameters shown, and chooses the other dropdowns 
	if (e.target == type)
	{
		//checks the type of type
		if (type->getLabel() == "SpriteCounter")
		{
			numberOfParametersLoaded = 2;
		}

		else if (type->getLabel() == "MultiSpriteCounter")
		{
			numberOfParametersLoaded = 4;

		}
		else if (type->getLabel() == "TimeoutScoreCount")
		{
			numberOfParametersLoaded = 2;
		}
	}

	else
	{
		cout << e.target->getLabel() << " was clicked!" << endl;
		for (int i = 0; i < numberOfParametersLoaded; i++)
		{
			if (e.target == paramType[i])
			{
				cout << paramType[i]->getName() << " was chosen!" << endl;
			}
		}
	}
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

void InspectorTerminationSet::saveCurrentTermination()
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
