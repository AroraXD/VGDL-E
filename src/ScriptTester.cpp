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
	VGDLParser vgdlP("test.txt");//creates a VGDL script at this location

	bool loop = true;
	int choice = 0;
	while (loop)
	{
		cout << "Which main segment would you like to work with now?: \n1)SpriteSet \n2)InteractionSet \n3)TerminationSet\n4)VGDL Creator \n5)Close program";
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
			workWithVGDLCreator(&vgdlP);
			break;
		case 5:
			cout << "Closing program..." << endl;
			loop = false;
			break;
		default:
			cout << "Invalid choice, choose again" << endl;
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
		cout << "What do you want to do?\n1)Add Sprite to list\n2)Delete sprite from list\3)Show list of Sprites\n4)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new sprite, ask for possible parameters, etc, and finally put the new sprite in the list
			addSpriteInList(ss);
			break;
		case 2:
			//ask the name of the sprite to be deleted, look it up in the sprite list, return true if found name and deleted it
			cout << "Not yet implemented"<<endl;
			break;
		case 3:
			//get sprite list and display it someway nice(create 'display' method around here)
			showSpriteList(ss);
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

void ScriptTester::workWithInteractionSet(InteractionSet* is)
{
	bool loop = true;
	int choice = 0;
	while (loop)
	{
		cout << "What do you want to do?\n1)Add Interaction to list\n2)Delete Interaction from list\3)Show list of Interactions\n4)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new interaction, ask for possible parameters, etc, and finally put the new interaction in the list
			addInteractionInList(is);
			break;
		case 2:
			//show interaction list, ask for index of interaction to remove, look it up in the interaction list, return true if found and deleted it
			cout << "Not yet implemented" << endl;
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
		cout << "What do you want to do?\n1)Add Termination to list\n2)Delete Termination from list\3)Show list of Terminations\n4)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new termination, ask for possible parameters, etc, and finally put the new termination in the list
			addTerminationInList(ts);
			break;
		case 2:
			//show termination list, ask for index of termination to remove, look it up in the termination list, return true if found and deleted it
			cout << "Not yet implemented" << endl;
			break;
		case 3:
			//get termination list and display it someway nice(create 'display' method around here)
			showTerminationList(ts);
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

void ScriptTester::workWithVGDLCreator(VGDLParser * vgdl)
{
	cout << "Not implemented yet" << endl;
}



//==================================================FLOW ADDING METHODS =========================================================

void ScriptTester::addSpriteInList(SpriteSet * ss)
{
	//same deal as methods above it, lock the program in a loop until user decides to return
	int choice = 0;

	cout << "Creating a new sprite....\nEnter a name of the new sprite(not checking for validation at this point): ";
	string name;
	cin >> name;
	cout << "Enter the type of the sprite: ";
	string stype;
	cin >> stype;
	//creates a basic sprite with just the name and type
	Sprite newSprite(name, stype);

	cout << "Add parameter?\n1) Yes 2)No\n";
	cin >> choice;
	if (choice == 1)
	{
		//asks for parameter value, now just accepts any strings
		addParameter(&newSprite);
		cout << "Adding sprite to list...";

	}
	else
	{
		//no parameters input, still adds sprite to list
		cout << "Adding sprite to list without parameters...\n";
	}
	//after name and possible parameter(s), add sprite to list
	ss->addSprite(newSprite);
	cout << "Sprite added.\n\n";
}

void ScriptTester::addParameter(Sprite * s)
{
	int choice = 0;
	bool loop = false;
	while (loop)
	{
		cout << "Enter the name of the parameter: ";
		string name;
		cin >> name;
		cout << "Enter the parameter's value: ";
		string value;
		cin >> value;
		//creates a new parameter and adds it to the parameter Sprite
		Parameter newP(name,value);
		s->addParameter(newP);
		cout << "Parameter added. Add another parameter?\n1)Yes 2)No\n ";
		cin >> choice;
		if (choice != 1)
			loop = false;
	}
}

void ScriptTester::addTerminationInList(TerminationSet * ts)
{
	//same deal as methods above it, lock the program in a loop until user decides to return
	int choice = 0;

	cout << "Creating a new Temination....\nEnter the type of the new termination(not checking for validation at this point): ";
	string type;
	cin >> type;

	//creates a basic termination with just the type
	Termination newT(type);

	cout << "Add parameter?\n1)Yes 2)No\n";
	cin >> choice;
	if (choice == 1)
	{
		//asks for parameter value, now just accepts any strings
		addParameter(&newT);
		cout << "Adding termination to list...";
	}
	else
	{
		//no parameters input, still adds sprite to list
		cout << "Adding termination to list without parameters...\n";
	}
	//after name and possible parameter(s), add sprite to list
	ts->addTermination(newT);
	cout << "Termination added.\n\n";
}

void ScriptTester::addParameter(Termination * t)
{
	int choice = 0;
	bool loop = false;
	while (loop)
	{
		cout << "Enter the name of the parameter: ";
		string name;
		cin >> name;
		cout << "Enter the parameter's value: ";
		string value;
		cin >> value;
		//creates a new parameter and adds it to the parameter Sprite
		Parameter newP(name, value);
		t->addParameter(newP);
		cout << "Parameter added. Add another parameter?\n1)Yes 2)No\n ";
		cin >> choice;
		if (choice != 1)
			loop = false;
	}
}

void ScriptTester::addInteractionInList(InteractionSet * is)
{
	//same deal as methods above it, lock the program in a loop until user decides to return
	int choice = 0;

	cout << "Creating a new Temination....\nEnter the name of the affected sprite(not checking for validation at this point): ";
	string sprite;
	cin >> sprite;

	vector<string> interactorSpritesList;//will hold all interactor sprites and send it to the new Interaction
	bool loop = true;

	cout << "Now input the name of the sprite(s) that interact with" + sprite<<endl;
	while (loop)
	{
		cout << "Enter the name of the interactor sprite: ";
		string interactorS;
		cin >> interactorS;
		interactorSpritesList.push_back(interactorS);
		cout << "Interactor sprite added. Add another interactor sprite?\n1)Yes\n 2)No\n";
		cin >> choice;
		if (choice != 1)//means no more interactor sprites are needed
			loop = false;
	}

	//creates a basic termination with just the type
	Interaction newI(sprite, interactorSpritesList);
	cout << "Basic interaction created\n";
	cout << "Add parameter?\n1)Yes 2)No\n";
	cin >> choice;
	if (choice == 1)
	{
		//asks for parameter value, now just accepts any strings
		addParameter(&newI);
		cout << "Adding interaction to list...";
	}
	else
	{
		//no parameters input, still adds sprite to list
		cout << "Adding interaction to list without parameters...\n";
	}
	//after name and possible parameter(s), add Interaction to list
	is->addInteraction(newI);
	cout << "Interaction added.\n\n";
}

void ScriptTester::addParameter(Interaction * i)
{
	int choice = 0;
	bool loop = false;
	while (loop)
	{
		cout << "Enter the name of the parameter: ";
		string name;
		cin >> name;
		cout << "Enter the parameter's value: ";
		string value;
		cin >> value;
		//creates a new parameter and adds it to the parameter Sprite
		Parameter newP(name, value);
		i->addParameter(newP);
		cout << "Parameter added. Add another parameter?\n1)Yes 2)No\n ";
		cin >> choice;
		if (choice != 1)
			loop = false;
	}
}

void ScriptTester::showSpriteList(SpriteSet * ss)
{
	cout << "Showing all sprites in sprite list..." << endl;
	for (int i = 0; i < ss->getSpriteList().size(); i++)
	{
		cout << "Sprite " + (i + 1) << ": " << endl;
		cout << "Name: " << ss->getSpriteList()[i].getName() << endl;
		cout << "Type: " << ss->getSpriteList()[i].getSpriteType() << endl;
		cout << "Parameters: todo" << endl;


	}
	cout << "\n\n";
}

void ScriptTester::showTerminationList(TerminationSet * ts)
{
	cout << "Showing all Terminations in Termination list..." << endl;
	for (int i = 0; i < ts->getTerminationList().size(); i++)
	{
		cout << "Termination " + (i + 1) << ": " << endl;
		cout << "Type: " << ts->getTerminationList()[i].getTerminationType() << endl;
		cout << "Parameters: todo\n\n" << endl;


	}
	cout << "\n\n";

}

void ScriptTester::showInteractionList(InteractionSet * is)
{
	cout << "Showing all Interactions in Interaction list..." << endl;
	for (int i = 0; i < is->getInteractionList().size(); i++)
	{
		cout << "Interaction" + (i + 1) << ": " << endl;
		cout << "Interacted sprite: " << is->getInteractionList()[i].getInteractedSprite() << endl;
		cout << "Interactor sprites: ";
		for (int j = 0; j < is->getInteractionList()[i].getInteractorSprites().size(); j++)
		{
			//gets each interactor sprite of this interaction
			cout << is->getInteractionList()[i].getInteractorSprites()[j]<< " ";
		}
		cout << endl;
		cout << "Parameters: todo\n\n" << endl;


	}
	cout << "\n\n";

}
