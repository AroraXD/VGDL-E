#pragma once
#include "TerminationSet.h"
#include "ofxDatGui.h"
#include "DataSet.h"//to get the info about the lists
#include <vector>

class InspectorTerminationSet
{
public:
	InspectorTerminationSet();
	InspectorTerminationSet(TerminationSet* ts);
	~InspectorTerminationSet();

	void draw();
	void update();

	void onButtonEvent(ofxDatGuiButtonEvent e);
	void onTextInputEvent(ofxDatGuiTextInputEvent e);
	void onDropdownEvent(ofxDatGuiDropdownEvent e);


	void addNewTermination();
	//clears all inputs to prepare for a new termination
	void clearInputs();
	//Loads a termination's values into the input fields and dropdown lists
	void loadTermination(Termination t);
	//Saves the termination in the current termination space.
	void saveCurrentTermination();
	//Loads next Termination(if got to last one, go to first one)
	void loadNextTermination();
	//Loads previous Termination(if got to first one, go to last one)
	void loadPreviousTermination();

	int getCurrentTermination();
	void setCurrentTermination(int t);

	int getNumberOfTerminations();
	void setNumberOfTerminations(int t);

private:

	TerminationSet* ts;//holds the Termination Set that will be used throughout the program


	//Buttons position variables
	int buttonsX = 150;
	int buttonsY = 200;


	//Buttons
	ofxDatGuiButton* nextButton;
	ofxDatGuiButton* previousButton;
	ofxDatGuiButton* saveTerminationButton;
	ofxDatGuiButton* addNewTerminationButton;
	
	ofxDatGuiDropdown* type;//Holds Termination Type
	//ofxDatGuiTextInput* value;

	std::vector<ofxDatGuiDropdown*> paramType;//Type of parameter accepted by Termination
	std::vector<ofxDatGuiTextInput*> paramValue;//Value of parameter

	int currentTermination = 0;
	int numberOfTerminations = 0;
	int numberOfParametersLoaded = 0;//holds the number of Parameters that will be loaded; depends on what user chooses in the dropdown value menu

	DataSet dt;
};


