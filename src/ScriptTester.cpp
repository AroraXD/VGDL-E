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
		cout << "\nWhat do you want to do?\n1)Add Sprite to list\n2)Modify sprite\n3)Delete sprite from list\n4)Show list of Sprites\n5)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new sprite, ask for possible parameters, etc, and finally put the new sprite in the list
			addSpriteInList(ss);
			break;
		case 2:
			//modify sprite
			modifySprite(ss);//NEEDS WORK, NOT MODIFYING YET SINCE WORKING WITH VECTORS IS SOMETIMES ANNOYING
			break;
		case 3:
			//ask the name of the sprite to be deleted, look it up in the sprite list, return true if found name and deleted it
			deleteSpriteFromList(ss);
			break;
		case 4:
			//get sprite list and display it someway nice(create 'display' method around here)
			showSpriteList(ss);
			break;
		case 5:
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
		cout << "\nWhat do you want to do?\n1)Add Interaction to list\n2)Modify Interaction\n3)Delete Interaction from list\n4)Show list of Interactions" << 
				"\n5)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new interaction, ask for possible parameters, etc, and finally put the new interaction in the list
			addInteractionInList(is);
			break;
		case 2://modify interaction
			modifyInteraction(is);
			break;
		case 3:
			//show interaction list, ask for index of interaction to remove, look it up in the interaction list, return true if found and deleted it
			deleteInteractionFromList(is);
			break;
		case 4:
			//get interaction list and display it someway nice(create 'display' method around here)
			showInteractionList(is);
			break;
		case 5:
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
		cout << "\nWhat do you want to do?\n1)Add Termination to list\n2)Modify Termination\n3)Delete Termination from list\n"<<
				"4)Show list of Terminations\n5)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new termination, ask for possible parameters, etc, and finally put the new termination in the list
			addTerminationInList(ts);
			break;
		case 2://modifies Termination
			modifyTermination(ts);
			break;
		case 3:
			//show termination list, ask for index of termination to remove, look it up in the termination list, return true if found and deleted it
			deleteTerminationFromList(ts);
			break;
		case 4:
			//get termination list and display it someway nice(create 'display' method around here)
			showTerminationList(ts);
			break;
		case 5:
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

//================================================================================ MODIFY METHODS ============================================================================


void ScriptTester::modifySprite(SpriteSet * ss)
{
	//shows sprites, asks user to pick one, then keep modifying it until user is satisfied
	showSpriteList(ss);
	cout << "Pick one sprite(by index): ";
	int spriteIndex;
	cin >> spriteIndex;

	//temp variables to use while modifying the object
	string str;//used for anything string-related inside switch
	int i;
	Sprite modifiedSprite;
	Parameter newParam;//will be used to add any parameters
	modifiedSprite = ss->getSpriteList()[spriteIndex - 1];
	bool loop = true;
	while (loop)
	{
		showSprite(modifiedSprite);
		cout << "\nWhat would you like to do with this sprite?\n1)Modify name\n2)Modify type\n3)Add parameter\n4)Remove parameter\n5)Change sprite's parent\n6)Return to previous menu\nChoice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1://Change name
			cout << "What's the sprite's new name?\nNew name: ";
			cin >> str;
			modifiedSprite.setName(str);
			break;
		case 2://change type
			cout << "What's the sprite's new type?\nNew type: ";
			cin >> str;
			modifiedSprite.setSpriteType(str);
			break;
		case 3://add parameter
			cout << "New parameter type: ";
			cin >> str;
			newParam.setParameterName(str);
			cout << "New parameter value: ";
			cin >> str;
			newParam.setParameterValue(str);
			modifiedSprite.addParameter(newParam);
			break;
		case 4://shows user parameters of this obj(with index), user chooses an index, removes chosen parameter
			showParameters(modifiedSprite);
			cout << "Type the index of the parameter to be deleted: ";
			cin >> i;
			modifiedSprite.deleteParameterAtPosition(i - 1);
			break;
		case 5://change parent's name
			cout << "What's the sprite's parent's name?\nParent's name: ";
			cin >> str;
			modifiedSprite.setParent(str);
			break;
		case 6:
			//returns to menu, so leave loop
			cout << "Returning to previous menu, saving changes..." << endl;
			loop = false;
			ss->modifySprite(modifiedSprite, spriteIndex - 1);
			break;
		default:
			cout << "Invalid choice.";
			break;


		}
	}
}

void ScriptTester::modifyTermination(TerminationSet* ts)
{
	//shows terminations, asks user to pick one, then keep modifying it until user is satisfied
	showTerminationList(ts);
	cout << "Pick one termination(by index): ";
	int terminationIndex;
	cin >> terminationIndex;

	//temp variables to use while modifying the object
	string str;//used for anything string-related inside switch
	int i;
	Termination modifiedTermination;
	Parameter newParam;//will be used to add any parameters
	modifiedTermination = ts->getTerminationList()[terminationIndex - 1];
	bool loop = true;
	while (loop)
	{
		showTermination(modifiedTermination);
		cout << "\nWhat would you like to do with this termination?\n1)Modify termination type\n2)Add parameter\n3)Remove parameter"<<
				"\n4)Return to previous menu\nChoice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1://Change termination type
			cout << "What's the termination's new type?\nNew type: ";
			cin >> str;
			modifiedTermination.setTerminationType(str);
			break;
		case 2://add parameter
			cout << "New parameter type: ";
			cin >> str;
			newParam.setParameterName(str);
			cout << "New parameter value: ";
			cin >> str;
			newParam.setParameterValue(str);
			modifiedTermination.addParameter(newParam);
			break;
		case 3://shows user parameters of this obj(with index), user chooses an index, removes chosen parameter
			showParameters(modifiedTermination);
			cout << "Type the index of the parameter to be deleted: ";
			cin >> i;
			modifiedTermination.deleteParameterAtPosition(i - 1);
			break;
		case 4:
			//returns to menu, so leave loop
			cout << "Returning to previous menu, saving changes..." << endl;
			loop = false;
			ts->modifyTermination(modifiedTermination, terminationIndex - 1);
			break;
		default:
			cout << "Invalid choice.";
			break;


		}
	}
}

void ScriptTester::modifyInteraction(InteractionSet * is)
{
	//shows terminations, asks user to pick one, then keep modifying it until user is satisfied
	showInteractionList(is);
	cout << "Pick one interaction(by index): ";
	int interactionIndex;
	cin >> interactionIndex;

	//temp variables to use while modifying the object
	string str;//used for anything string-related inside switch
	int i;
	Interaction modifiedInteraction;
	Parameter newParam;//will be used to add any parameters
	modifiedInteraction = is->getInteractionList()[interactionIndex - 1];
	bool loop = true;
	while (loop)
	{
		showInteraction(modifiedInteraction);
		cout << "\nWhat would you like to do with this Interaction?\n1)Modify interacted sprite"<<
				"\n2)Add interactor sprite\n3)Remove interactor sprite\n4)Modify consequence"<<
				"\n5)Add parameter\n6)Remove parameter" <<
				"\n7)Return to previous menu\nChoice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1://Change interacted sprite
			cout << "What's the Interaction's new interacted sprite?\nNew affected sprite: ";
			cin >> str;
			modifiedInteraction.setInteractedSprite(str);
			break;
		case 2://add a new interactor sprite
			cout << "Give the name of the new interactor sprite: ";
			cin >> str;
			modifiedInteraction.addNewInteractorSprite(str);
			cout << "Interactor sprite added!" << endl;
			break;
		case 3://delete an interactor sprite from the list
			cout << "To be implemented" << endl;
			break;
		case 4://modify consequence
			cout << "Give the new consequence: ";
			cin >> str;
			modifiedInteraction.setInteractionType(str);
			break;
		case 5://add parameter
			cout << "New parameter type: ";
			cin >> str;
			newParam.setParameterName(str);
			cout << "New parameter value: ";
			cin >> str;
			newParam.setParameterValue(str);
			modifiedInteraction.addParameter(newParam);
			break;
		case 6://shows user parameters of this obj(with index), user chooses an index, removes chosen parameter
			showParameters(modifiedInteraction);
			cout << "Type the index of the parameter to be deleted: ";
			cin >> i;
			modifiedInteraction.deleteParameterAtPosition(i - 1);
			break;
		case 7:
			//returns to menu, so leave loop
			cout << "Returning to previous menu, saving changes..." << endl;
			loop = false;
			is->modifyInteraction(modifiedInteraction, interactionIndex - 1);
			break;
		default:
			cout << "Invalid choice.";
			break;

		}
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
	showParameters(ss->getSpriteList()[index]);
}

void ScriptTester::showSprite(Sprite s)
{
	cout << "\nSelected Sprite: " << endl;
	cout << "Name: " << s.getName() << endl;
	cout << "Type: " << s.getSpriteType() << endl;
	cout << "Parameters: " << endl;
	//puts parameters one by one, name and value
	showParameters(s);
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
	showParameters(ts->getTerminationList()[index]);
}

void ScriptTester::showTermination(Termination t)
{
	cout << "\nTermination: " << endl;
	cout << "Type: " << t.getTerminationType() << endl;
	cout << "Parameters: " << endl;
	showParameters(t);
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
	cout << "Consequence: " << is->getInteractionList()[index].getInteractionType() <<endl;
	cout << "Parameters: " << endl;
	showParameters(is->getInteractionList()[index]);
}

void ScriptTester::showInteraction(Interaction i)
{
	cout << "\nInteraction: " << endl;
	cout << "Interacted sprite: " << i.getInteractedSprite() << endl;
	cout << "Interactor sprites: ";
	for (int j = 0; j < i.getInteractorSprites().size(); j++)
	{
		//gets each interactor sprite of this interaction
		cout << i.getInteractorSprites()[j] << " ";
	}
	cout << "Consequence: " << i.getInteractionType() << endl;
	cout << "Parameters: " << endl;
	showParameters(i);
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

void ScriptTester::showParameters(Sprite s)
{
	for (int j = 0; j < s.getParameterList().size(); j++)
	{
		cout << "Parameter " << (j + 1) << endl;
		cout << "Name: " << s.getParameterList()[j].getParameterName() << endl;
		cout << "Value: " << s.getParameterList()[j].getParameterValue() << endl;

	}
}

void ScriptTester::showParameters(Termination t)
{
	for (int j = 0; j < t.getParameterList().size(); j++)
	{
		cout << "Parameter " << (j + 1) << endl;
		cout << "Name: " << t.getParameterList()[j].getParameterName() << endl;
		cout << "Value: " << t.getParameterList()[j].getParameterValue() << endl;

	}
}

void ScriptTester::showParameters(Interaction i)
{
	for (int j = 0; j < i.getParameterList().size(); j++)
	{
		cout << "Parameter " << (j + 1) << endl;
		cout << "Name: " << i.getParameterList()[j].getParameterName() << endl;
		cout << "Value: " << i.getParameterList()[j].getParameterValue() << endl;

	}
}
