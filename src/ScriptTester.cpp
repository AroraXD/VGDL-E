#include "ScriptTester.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


ScriptTester::ScriptTester()
{
	

}

ScriptTester::~ScriptTester()
{
}

void ScriptTester::runScriptTest(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet)
{
	//gets the 3 parameters, creates an instance of the VGDL Parser, and goes into a loop to fill out the values to use for the build
	VGDLParser vgdlP("test");//creates a VGDL script at this location

	bool loop = true;
	int choice = 0;
	while (loop)
	{
		cout << "\nWhich main segment would you like to work with now? \n1)SpriteSet \n2)InteractionSet \n3)TerminationSet\n4)VGDL Creator \n5)Close program\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			workWithSpriteSet(&spriteSet);
			break;
		case 2:
			workWithInteractionSet(&interactionSet);
			break;
		case 3:
			workWithTerminationSet(&terminationSet);
			break;

		case 4:
			workWithVGDLCreator(&vgdlP, &spriteSet,&interactionSet, &terminationSet);
			break;
		case 5:
			cout << "Closing program..." << endl;
			loop = false;
			break;
		default:
			cout << "Invalid choice, choose again\n" << endl;
			break;
		}



	}


}

void ScriptTester::workWithSpriteSet(SpriteSet* ss)
{
	bool loop = true;
	int choice = 0;
	while(loop)
	{ 
		cout << "\nWhat do you want to do?\n1)Add Sprite to list\n2)Delete sprite from list\n3)Show list of Sprites\n4)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new sprite, ask for possible parameters, etc, and finally put the new sprite in the list
			addSpriteInList(ss);
			break;
		case 2:
			//ask the name of the sprite to be deleted, look it up in the sprite list, return true if found name and deleted it
			deleteSpriteFromList(ss);
			break;
		case 3:
			//get sprite list and display it someway nice(create 'display' method around here)
			showSpriteList(ss);
			break;
		case 4:
			cout << "\nReturning to main menu...\n" << endl;
			loop = false;
			break;
		default:
			cout << "\nInvalid choice" << endl;
			break;
		}
	}
}

void ScriptTester::workWithInteractionSet(InteractionSet* is)
{
	bool loop = true;
	int choice = 0;
	while (loop)
	{
		cout << "\nWhat do you want to do?\n1)Add Interaction to list\n2)Delete Interaction from list\n3)Show list of Interactions\n4)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new interaction, ask for possible parameters, etc, and finally put the new interaction in the list
			addInteractionInList(is);
			break;
		case 2:
			//show interaction list, ask for index of interaction to remove, look it up in the interaction list, return true if found and deleted it
			deleteInteractionFromList(is);
			break;
		case 3:
			//get interaction list and display it someway nice(create 'display' method around here)
			showInteractionList(is);
			break;
		case 4:
			cout << "Returning to main menu...\n" << endl;
			loop = false;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}
}

void ScriptTester::workWithTerminationSet(TerminationSet* ts)
{
	bool loop = true;
	int choice = 0;
	while (loop)
	{
		cout << "\nWhat do you want to do?\n1)Add Termination to list\n2)Delete Termination from list\n3)Show list of Terminations\n4)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new termination, ask for possible parameters, etc, and finally put the new termination in the list
			addTerminationInList(ts);
			break;
		case 2:
			//show termination list, ask for index of termination to remove, look it up in the termination list, return true if found and deleted it
			deleteTerminationFromList(ts);
			break;
		case 3:
			//get termination list and display it someway nice(create 'display' method around here)
			showTerminationList(ts);
			break;
		case 4:
			cout << "\nReturning to main menu...\n" << endl;
			loop = false;
			break;
		default:
			cout << "\nInvalid choice" << endl;
			break;
		}
	}
}

void ScriptTester::workWithVGDLCreator(VGDLParser * vgdl, SpriteSet * ss, InteractionSet * is, TerminationSet * ts)
{
	cout << "Creating a VGDL script in the root directory of the program, named " << vgdl->getPath() << endl;
	if (vgdl->createVGDLScript(*ss, *is, *ts))
		cout << "Script created!\n" << endl;
	else
		cout << "Failed to create script...for some reason" << endl;
}





//==================================================FLOW ADDING METHODS =========================================================

void ScriptTester::addSpriteInList(SpriteSet * ss)
{
	//same deal as methods above it, lock the program in a loop until user decides to return
	int choice = 0;

	cout << "\nCreating a new sprite....\nEnter a name of the new sprite(not checking for validation at this point): ";
	string name;
	cin >> name;
	cout << "\nEnter the type of the sprite: ";
	string stype;
	cin >> stype;
	//creates a basic sprite with just the name and type
	Sprite newSprite(name, stype);

	cout << "\nAdd parameter?\n1) Yes 2)No\n";
	cin >> choice;
	if (choice == 1)
	{
		//asks for parameter value, now just accepts any strings
		cout << "Adding parameter...";
		addParameter(&newSprite);
		cout << "\nAdding sprite to list...";

	}
	else
	{
		//no parameters input, still adds sprite to list
		cout << "\nAdding sprite to list without parameters...\n";
	}
	//after name and possible parameter(s), add sprite to list
	ss->addSprite(newSprite);
	cout << "\nSprite added.\n\n";
}

void ScriptTester::addParameter(Sprite * s)
{
	int choice = 0;
	bool loop = true;
	while (loop)
	{
		cout << "\nEnter the name of the parameter: ";
		string name;
		cin >> name;
		cout << "\nEnter the parameter's value: ";
		string value;
		cin >> value;
		//creates a new parameter and adds it to the parameter Sprite
		Parameter newP(name,value);
		s->addParameter(newP);
		cout << "\nParameter added. Add another parameter?\n1)Yes 2)No\n";
		cin >> choice;
		if (choice != 1)
			loop = false;
	}
}

void ScriptTester::addTerminationInList(TerminationSet * ts)
{
	//same deal as methods above it, lock the program in a loop until user decides to return
	int choice = 0;

	cout << "\nCreating a new Temination....\nEnter the type of the new termination(not checking for validation at this point): ";
	string type;
	cin >> type;

	//creates a basic termination with just the type
	Termination newT(type);

	cout << "\nAdd parameter?\n1)Yes 2)No\n";
	cin >> choice;
	if (choice == 1)
	{
		//asks for parameter value, now just accepts any strings
		addParameter(&newT);
		cout << "\nAdding termination to list...";
	}
	else
	{
		//no parameters input, still adds sprite to list
		cout << "\nAdding termination to list without parameters...\n";
	}
	//after name and possible parameter(s), add sprite to list
	ts->addTermination(newT);
	cout << "\nTermination added.\n\n";
}

void ScriptTester::addParameter(Termination * t)
{
	int choice = 0;
	bool loop = true;
	while (loop)
	{
		cout << "\nEnter the name of the parameter: ";
		string name;
		cin >> name;
		cout << "\nEnter the parameter's value: ";
		string value;
		cin >> value;
		//creates a new parameter and adds it to the parameter Sprite
		Parameter newP(name, value);
		t->addParameter(newP);
		cout << "\nParameter added. Add another parameter?\n1)Yes 2)No\n";
		cin >> choice;
		if (choice != 1)
			loop = false;
	}
}

void ScriptTester::addInteractionInList(InteractionSet * is)
{
	//same deal as methods above it, lock the program in a loop until user decides to return
	int choice = 0;

	cout << "\nCreating a new Interaction....\nEnter the name of the affected sprite(not checking for validation at this point): ";
	string sprite;
	cin >> sprite;

	vector<string> interactorSpritesList;//will hold all interactor sprites and send it to the new Interaction
	bool loop = true;

	cout << "\nNow input the name of the sprite(s) that interact with " + sprite<<endl;
	while (loop)
	{
		cout << "\nEnter the name of the interactor sprite: ";
		string interactorS;
		cin >> interactorS;
		interactorSpritesList.push_back(interactorS);
		cout << "\nInteractor sprite added. Add another interactor sprite?\n1)Yes\n2)No\n";
		cin >> choice;
		if (choice != 1)//means no more interactor sprites are needed
			loop = false;
	}
	cout << "Enter the consequence of this Interaction: ";
	string consequence;
	cin >> consequence;
	//creates a basic interaction with the interacted sprites and the consequence
	Interaction newI(sprite, interactorSpritesList, consequence);
	cout << "\nBasic interaction created\n";
	cout << "\nAdd parameter?\n1)Yes 2)No\n";
	cin >> choice;
	if (choice == 1)
	{
		//asks for parameter value, now just accepts any strings
		addParameter(&newI);
		cout << "\nAdding interaction to list...";
	}
	else
	{
		//no parameters input, still adds sprite to list
		cout << "\nAdding interaction to list without parameters...\n";
	}
	//after name and possible parameter(s), add Interaction to list
	is->addInteraction(newI);
	cout << "\nInteraction added.\n\n";
}

void ScriptTester::addParameter(Interaction * i)
{
	int choice = 0;
	bool loop = true;
	while (loop)
	{
		cout << "\nEnter the name of the parameter: ";
		string name;
		cin >> name;
		cout << "\nEnter the parameter's value: ";
		string value;
		cin >> value;
		//creates a new parameter and adds it to the parameter Sprite
		Parameter newP(name, value);
		i->addParameter(newP);
		cout << "\nParameter added. Add another parameter?\n1)Yes 2)No\n";
		cin >> choice;
		if (choice != 1)
			loop = false;
	}
}

//=========================================================================== DELETE METHODS ==============================================================================================


void ScriptTester::deleteSpriteFromList(SpriteSet * ss)
{
	//shows sprites, asks user to give sprite name, delete sprite from name 
	showSpriteList(ss);
	cout << "\nEnter the name of the sprite to be deleted: ";
	string spriteName;
	cin >> spriteName;
	if (ss->deleteSprite(spriteName))
		cout << "Sprite successfully deleted" << endl;
	else
		cout << "Error: sprite not found in list, deletion failed.\n" << endl;

}

void ScriptTester::deleteTerminationFromList(TerminationSet * ts)
{
	//shows termination list, asks for index of termination to be deleted, deletes it
	showTerminationList(ts);
	cout << "Please give the number of the termination you wish to delete: ";
	int tNumber;
	cin >> tNumber;
	if (ts->deleteTermination(tNumber))
		cout << "Termination successfully deleted";
	else
		cout << "Error: termination deletion failed.\n" << endl;
}

void ScriptTester::deleteInteractionFromList(InteractionSet * is)
{
	//shows termination list, asks for index of termination to be deleted, deletes it
	showInteractionList(is);
	cout << "Please give the number of the interaction you wish to delete: ";
	int tNumber;
	cin >> tNumber;
	if (is->deleteInteraction(tNumber))
		cout << "Interation successfully deleted";
	else
		cout << "Error: interaction deletion failed.\n" << endl;
}


//=========================================================================== DISPLAY METHODS ==========================================================================


void ScriptTester::showSprite(SpriteSet * ss, int index)
{
	cout << "\nSprite " << (index + 1) << ": " << endl;
	cout << "Name: " << ss->getSpriteList()[index].getName() << endl;
	cout << "Type: " << ss->getSpriteList()[index].getSpriteType() << endl;
	cout << "Parameters: " << endl;
	//puts parameters one by one, name and value
	for (int j = 0; j < ss->getSpriteList()[index].getParameterList().size(); j++)
	{
		cout << "Name: " << ss->getSpriteList()[index].getParameterList()[j].getParameterName() << endl;
		cout << "Value: " << ss->getSpriteList()[index].getParameterList()[j].getParameterValue() << endl;

	}
}

void ScriptTester::showSpriteList(SpriteSet * ss)
{
	cout << "\nShowing all sprites in sprite list..." << endl;
	for (int i = 0; i < ss->getSpriteList().size(); i++)
	{
		showSprite(ss, i);
	}
	cout << "\n\n";
}

void ScriptTester::showTermination(TerminationSet * ts, int index)
{
	cout << "\nTermination " << (index + 1) << ": " << endl;
	cout << "Type: " << ts->getTerminationList()[index].getTerminationType() << endl;
	cout << "Parameters: " << endl;
	for (int j = 0; j < ts->getTerminationList()[index].getParameterList().size(); j++)
	{
		cout << "Name: " << ts->getTerminationList()[index].getParameterList()[j].getParameterName() << endl;
		cout << "Value: " << ts->getTerminationList()[index].getParameterList()[j].getParameterValue() << endl;

	}
}

void ScriptTester::showTerminationList(TerminationSet * ts)
{
	cout << "\nShowing all Terminations in Termination list..." << endl;
	for (int i = 0; i < ts->getTerminationList().size(); i++)
	{
		showTermination(ts, i);

	}
	cout << "\n\n";

}

void ScriptTester::showInteraction(InteractionSet * is, int index)
{
	cout << "\nInteraction" << (index + 1) << ": " << endl;
	cout << "Interacted sprite: " << is->getInteractionList()[index].getInteractedSprite() << endl;
	cout << "Interactor sprites: ";
	for (int j = 0; j < is->getInteractionList()[index].getInteractorSprites().size(); j++)
	{
		//gets each interactor sprite of this interaction
		cout << is->getInteractionList()[index].getInteractorSprites()[j] << " ";
	}
	cout << endl;
	cout << "Parameters: " << endl;
	for (int j = 0; j < is->getInteractionList()[index].getParameterList().size(); j++)
	{
		cout << "Name: " << is->getInteractionList()[index].getParameterList()[j].getParameterName() << endl;
		cout << "Value: " << is->getInteractionList()[index].getParameterList()[j].getParameterValue() << endl;

	}
}

void ScriptTester::showInteractionList(InteractionSet * is)
{
	cout << "\nShowing all Interactions in Interaction list..." << endl;
	for (int i = 0; i < is->getInteractionList().size(); i++)
	{
		showInteraction(is, i);
	}
	cout << "\n\n";

}
