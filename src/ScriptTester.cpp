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


//=================================================== MENU METHODS ========================================================


void ScriptTester::runScriptTest(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet, LevelMapping levelMapping, GlobalGameParameters globalGameParameters)
{
	//gets the 3 parameters, creates an instance of the VGDL Parser, and goes into a loop to fill out the values to use for the build
	VGDLParser vgdlP("test");//creates a VGDL script at this location
	bool loop = true;
	int choice = 0;
	while (loop)
	{
		cout << "\nWhich would you like to work with now? \n1)SpriteSet\n" <<
				"2)InteractionSet \n3)TerminationSet\n"<<
				"4)LevelMapping\n5)Global Game Parameters \n"<<
				"6)Write VGDL file \n7)Read VGDL File \n8)Run VGDL Script\n9)Close program\n";
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
			workWithLevelMapping(&levelMapping);
			break;
		case 5:
			workWithGlobalGameParameters(&globalGameParameters);
			break;

		case 6:
			workWithVGDLCreator(&vgdlP, &spriteSet,&interactionSet, &terminationSet, &levelMapping, &globalGameParameters);
			break;
		case 7:
			//loadVGDLFile(placeholder);
			break;
		case 8:
			runVGDLGame(vgdlP);
			break;
		case 9:

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
		cout << "\nWhat do you want to do?\n1)Add Sprite to list\n2)Modify sprite\n3)Delete sprite from list\n" <<
				"4)Show list of Sprites\n5)Show parent tree\n6)Show root sprite list\n7)Return to main menu\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//ask for info on new sprite, ask for possible parameters, etc, and finally put the new sprite in the list
			addSpriteInList(ss);
			break;
		case 2:
			//modify sprite
			modifySprite(ss);
			break;
		case 3:
			//ask the name of the sprite to be deleted, look it up in the sprite list, return true if found name and deleted it
			deleteSpriteFromList(ss);
			break;
		case 4:
			//get sprite list and display it someway nice(create 'display' method around here)
			showSpriteList(ss);
			break;
		case 5://shows parent and child tree
			showSpriteParentTree(ss);
			break;
		case 6:
			showRootSprites(ss);
			break;
		case 7:
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

void ScriptTester::workWithLevelMapping(LevelMapping * lm)
{
	bool loop = true;
	int newW, newH;//receive values for the new width and height of the map
	int choice = 0;
	while (loop)
	{
		cout << "\nWhat do you want to do?\n1)Add a character map(assign a sprite to a character)\n" <<
			"2)Modify a character map\n" <<
			"3)Delete a character map\n" <<
			"4)Create an ASCII map(based on current size of " << lm->getWidth() << "x" << lm->getHeight() <<")\n"<<
			"5)Resize map\n" <<
			"6)Show map characters\n"<<
			"7)Show map\n"<<
			"8)Exit\nChoice: "
			<<endl;
		cin >>choice;
		switch (choice)
		{
		case 1:
			addMapCharacterInList(lm);
			break;
		case 2:
			modifyMapCharacter(lm);
			break;
		case 3:
			deleteMapCharacterFromList(lm);
			break;
		case 4:
			//todo
			addMap(lm);
			break;
		case 5:
			cout << "Enter new map width: ";
			cin >> newW;
			cout << "Enter new map height: ";
			cin >> newH;
			lm->resizeMap(newW, newH);
			break;
		case 6:
			showLevelMapping(lm);
			break;
		case 7:
			//TODO: to implement
			showMap(lm);
			break;
		case 8:
			loop = false;
			break;
		default:
			cout << "\nInvalid choice. " << endl;

		}

	}
}

void ScriptTester::workWithGlobalGameParameters(GlobalGameParameters * ggp)
{
	bool loop = true;
	int choice = 0;
	while (loop)
	{
		cout << "\nWhat do you want to do?\n1)Add a game parameter\n" <<
			"2)Modify a game parameter\n" <<
			"3)Delete a game parameter\n" <<
			"4)Show Parameters\n"<<
			"5)Exit\nChoice: "
			<< endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//add ggp
			addGlobalParameter(ggp);
			break;
		case 2:
			//modify a ggp
			modifyGlobalParameter(ggp);
			break;
		case 3:
			//delete a ggp
			deleteGlobalParameters(ggp);
			break;
		case 4:
			//show all ggps
			showGlobalParameters(ggp);
			break;
		case 5:
			//break out of loop
			loop = false;
			break;
		default:
			cout << "\nInvalid choice. " << endl;
			break;

		}

	}
}

void ScriptTester::workWithVGDLCreator(VGDLParser * vgdl, SpriteSet * ss, InteractionSet * is, TerminationSet * ts, LevelMapping* lm, GlobalGameParameters* ggp)
{
	cout << "Give a name for the script you are about to create: ";
	string scriptName;
	cin >> scriptName;
	vgdl->setFileName(scriptName);
	cout << "Creating a VGDL script in the root directory of the program, named " << vgdl->getPath() << endl;
	if (vgdl->createVGDLScript(ss, *is, *ts, *lm, *ggp))
	{
		cout << "Script created!\n" << endl;
		setScriptWritten(true);
	}
	else
		cout << "Failed to create script...for some reason" << endl;
}

void ScriptTester::loadVGDLFile(std::ofstream fileToRead)
{
	//TODO
	cout << "To be implemented" << endl;
	//setScriptLoaded(true);
}

void ScriptTester::runVGDLGame(VGDLParser vgdlp)
{
	if(scriptWasLoaded()||scriptWasWritten())
	{
		string sysString = "java -jar vgdlRunner.jar ";//GOTTA MANUALLY ADD JAVA PATH?
		sysString += vgdlp.getFileName();

		const char* c = sysString.c_str();//...and need to make string into char* to use with system
		system(c);//actually calls VGDL
		//TODO: Problem: this closes the program once it ends, gotta find a way to not do so
	}

	else
	{
		cout << "Cannot run VGDL program, since no VGDL script was saved/loaded" << endl;
	}

}





//==================================================FLOW ADDING METHODS =========================================================

void ScriptTester::addSpriteInList(SpriteSet * ss)
{
	//same deal as methods above it, lock the program in a loop until user decides to return
	int choice = 0;
	int pIndex=0;

	cout << "\nCreating a new sprite....\nEnter a name of the new sprite(not checking for validation at this point): ";
	string name;
	cin >> name;
	cout << "\nEnter the type of the sprite(enter 'none' if sprite doesn't have/inherits its type): ";
	string stype;
	cin >> stype;
	if (stype == "none")
		stype = "";
	//creates a basic sprite with just the name and type
	bool spriteHasParent;
	cout << "Does the sprite have a parent?\n1)Yes  2)No\n";
	cin >> choice;
	if (choice == 1)
	{
		showSpriteList(ss);
		cout << "Choose index of parent: ";
		cin >> pIndex;
		spriteHasParent = true;
	}
	else
	{
		spriteHasParent = false;
	}
	Sprite* newSprite = new Sprite(name, stype, spriteHasParent);





	cout << "\nAdd parameter?\n1) Yes 2)No\n";
	cin >> choice;
	if (choice == 1)
	{
		//asks for parameter value, now just accepts any strings
		cout << "Adding parameter...";
		addParameter(newSprite);
		cout << "\nAdding sprite to list...";

	}
	else
	{
		//no parameters input, still adds sprite to list
		cout << "\nAdding sprite to list without parameters...\n";
	}
	//after name and possible parameter(s), add sprite to list
	ss->addSprite(newSprite);//this also deals with the possible root sprite issue

	//deals with parenting
	if (spriteHasParent)
	{
		cout << "Fixing child-parent relationships for " << newSprite->getName() << endl;
		ss->addChildToSprite(ss->getSpriteList()[pIndex - 1], newSprite);
	}
	
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

void ScriptTester::addMapCharacterInList(LevelMapping * lm)
{
	cout << "Enter the character that will be associated with the sprite(s): ";
	char newChar;
	int choice = 0;
	bool loop = true;
	string newSprite;
	vector<string> sprites;

	cin >> newChar;
	//checks if character isn't already in the list, to avoid duplicates
	if (lm->characterIsInList(newChar))
	{
		cout << "Character already exists in list!";
		return;
	}


	//gets all the sprites 
	while (loop)
	{
		cout << "Enter new sprite to associate with character: ";
		cin >> newSprite;
		sprites.push_back(newSprite);
		cout << "Sprite added. Add another one? 1: Yes / 2: No\n" << endl;
		if (choice != 1)
			loop = false;

	}
	//with all the info, create a character map
	lm->addCharacterToList(newChar, sprites);
}

void ScriptTester::addGlobalParameter(GlobalGameParameters * ggp)
{
	cout << "\nEnter the name of the parameter: ";
	string name;
	cin >> name;
	cout << "\nEnter the parameter's value: ";
	string value;
	cin >> value;
	//creates a new parameter and adds it to the parameter Sprite
	Parameter newP(name, value);
	ggp->addParameter(newP);
}

void ScriptTester::addMap(LevelMapping * lm)
{
	if (lm->getHeight() < 1 || lm->getWidth() < 1)
	{
		cout << "Cannot create map; map dimensions are too small" << endl;
		return;
	}
	vector <string> mapLines;
	string line;
	cout << "Create " << lm->getHeight() << " lines of " << lm->getWidth() <<
			" valid map characters to populate the map(or input \"CANCEL\" to cancel the map creation): " << endl;
	for (int i = 0; i < lm->getHeight(); i++)
	{
		cout << "Line " << i + 1 << ": ";
		cin >> line;
		cout << "Line given: " << line << endl;
		if (line == "CANCEL")
		{
			//cancelling line
			return;
		}
		while (!lm->isValidMapLine(line)/*<<<----giving error*/|| line.size()!=lm->getWidth())
		{
			cout << "Error: invalid characters/unnaceptable amount of characters.\n"<<
				"Please reinsert the line(or input \"CANCEL\" to cancel the map creation): ";
			cin >> line;
			if (line == "CANCEL")
				return;
		}
		//if it got to here, means user input a valid line
		mapLines.push_back(line);


	}
	//once all lines are added, add whole vector to map
	lm->clearMap();
	lm->setMap(mapLines);

}

void ScriptTester::getMapFromLevelEditor()
{
	//TO IMPLEMENT WHEN I HAVE ENOUGH INFO ABOUT THE FRONTEND
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
	Parameter newParam;//will be used to add any parameters

	//just get the sprite-to-be-modified's pointer and modify it on the fly
	Sprite* modifiedSprite = new Sprite();
	*modifiedSprite = *(ss->getSpriteList()[spriteIndex - 1]);
	bool loop = true;
	while (loop)
	{
		showSprite(modifiedSprite);
		cout << "\nWhat would you like to do with this sprite?\n1)Modify name\n2)Modify type\n3)Add parameter\n4)Remove parameter\n5)Change sprite's parent\n6)Return to previous menu\nChoice: ";
		int choice, index;
		cin >> choice;
		switch (choice)
		{
		case 1://Change name
			cout << "What's the sprite's new name?\nNew name: ";
			cin >> str;
			modifiedSprite->setName(str);
			break;
		case 2://change type
			cout << "What's the sprite's new type?\nNew type: ";
			cin >> str;
			modifiedSprite->setSpriteType(str);
			break;
		case 3://add parameter
			cout << "New parameter type: ";
			cin >> str;
			newParam.setParameterName(str);
			cout << "New parameter value: ";
			cin >> str;
			newParam.setParameterValue(str);
			modifiedSprite->addParameter(newParam);
			break;
		case 4://shows user parameters of this obj(with index), user chooses an index, removes chosen parameter
			showParameters(modifiedSprite);
			cout << "Type the index of the parameter to be deleted: ";
			cin >> i;
			modifiedSprite->deleteParameterAtPosition(i - 1);
			break;
		case 5://change parent
			changeSpriteParent(modifiedSprite, ss);
			break;

		case 6:
			//returns to menu, so leave loop
			cout << "Returning to previous menu, saving changes..." << endl;
			loop = false;
			//save new sprite's position, replacing old one
			ss->modifySprite(modifiedSprite, spriteIndex - 1);
			break;
		default:
			cout << "Invalid choice.";
			break;


		}
	}
}

void ScriptTester::changeSpriteParent(Sprite * s, SpriteSet* ss)
{
	//cout << "Not implemented yet" << endl;
	int index;
	showSpriteList(ss);
	cout << "What's the sprite's parent's index?\nParent's index(if sprite has no parent anymore, type '0'): ";
	cin >> index;

	//test couts
	cout << "Sprite: " << s << endl;
	cout << "Sprite's current parent: " << s->getParent() << endl;

	cout << index << endl;

	if (index == 0)
	{
		cout << "Deleting current parent and adding NULL" << endl;
		cout << "Sprite's new parent(before change): " << NULL << endl;

		//new parent sprite is NULL(BROKEN, FIX)
		if (ss->changeParenthood(s->getParent(), NULL, s))//BROKEN LINE
		{
			cout << "Sprite parent succesfully erased." << endl;
			cout << "Sprite's new parent(after change): " << s->getParent() << endl;

			cout << "Sprite: " << s << endl;

		}

	}


	else if (ss->changeParentHood(s->getParent(), index - 1, s))//bugging for some reason
	{
		cout << "Sprite's new parent(before change): " << ss->getSpriteList()[index - 1] << endl;

		cout << "Sprite parent changed succesfully" << endl;

		cout << "Sprite's new parent(after change): " << s->getParent() << endl;
		cout << "Sprite: " << s << endl;
	}

	else
		cout << "Error: could not change sprite's parent" << endl;
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

void ScriptTester::modifyMapCharacter(LevelMapping * lm)
{
	//shows a list of the character maps, asks user to pick 1 by index, modifies it
	showLevelMapping(lm);
	int index = 0;
	int choice = 0;
	char newChar;
	string newSprite;
	bool loop = true;

	cout << "Pick a map character by its index: ";
	cin >> index;
	MapCharacter modifiedMapChar = lm->getCharacterList()[index-1];

	while (loop)
	{
		cout << endl;
		showMapCharacter(lm->getCharacterList()[index - 1]);
		cout << "\nWhat do you want to do?\n1)Change its character\n2)Add a sprite\n" <<
				"3)Delete a sprite\n4)Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the new character for this map character: ";
			cin >> newChar;
			lm->modifyCharacterFromObj(index-1, newChar);
			break;
		case 2:
			//adds a new sprite
			cout << "Type the name of the sprite to be added: ";
			cin >> newSprite;
			if (lm->addSpriteToObj(index-1, newSprite))
				cout << "Sprite added succesfully";
			else
				cout << "Error: could not add sprite";
			break;
		case 3:
			//deletes a sprite
			cout << "Type the name of the sprite to be deleted: ";
			cin >> newSprite;
			if (lm->deleteSpriteFromObj(index-1, newSprite))
				cout << "Sprite deleted successfully";
			else
				cout << "Error: Could not delete sprite(not found, probably). Maybe you typed it wrong?";

			break;
		case 4:
			//saves modified mapChar, breaks loop
			//lm->modifyWholeObj(index-1, modifiedMapChar);
			loop = false;
			break;
		default:
			cout << "Invalid character, input another one.";
			break;

		}
	}


}

void ScriptTester::modifyGlobalParameter(GlobalGameParameters * ggp)
{
	//shows parameters, asks for user to choose one, asks what they want to modify, do it, return
	showGlobalParameters(ggp);
	cout << "Choose a parameter to modify: ";
	int index = 0;
	int choice = 0;
	string typeValue;
	cin >> index;
	if (index >= ggp->getParameterList().size())
	{
		cout << "Parameter out of bounds." << endl;
		return;
	}
	Parameter newGlobalParameter = ggp->getParameterList()[index-1];
	
	bool loop = true;
	while (loop)
	{
		cout << "\nWhat do you want to change?\n1)Parameter type\n2)Parameter value\n3)Save and exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter new parameter type: ";
			cin >> typeValue;
			newGlobalParameter.setParameterName(typeValue);
			break;
		case 2:
			cout << "Enter new parameter value: ";
			cin >> typeValue;
			newGlobalParameter.setParameterValue(typeValue);
			break;
		case 3:
			//deletes old parameter, saves new parameter and exit
			ggp->deleteParameterAtPosition(index-1);
			ggp->addParameter(newGlobalParameter);
			loop = false;
			break;

		default:
			cout << "Invalid choice, please choose again.";
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

void ScriptTester::deleteMapCharacterFromList(LevelMapping * lm)
{
	//shows all characters, choose to delete one based on index
	showLevelMapping(lm);
	int index = 0;
	cout << "Choose index of mapCharacter to be deleted: ";
	cin >> index;
	if (lm->deleteCharacterFromList(index-1))
		cout << "Character deleted successfully";
	else
		cout << "Error: could not delete character";

}

void ScriptTester::deleteGlobalParameters(GlobalGameParameters * ggp)
{
	//shows parameters, asks to delete one based on index
	showGlobalParameters(ggp);
	int index = 0;
	cout << "Choose which parameter you will delete: ";
	cin >> index;
	ggp->deleteParameterAtPosition(index-1);

}


//=========================================================================== DISPLAY METHODS ==========================================================================




void ScriptTester::showSprite(SpriteSet * ss, int index)
{
	cout << "\nSprite " << (index + 1) << ": " << endl;
	cout << "Name: " << ss->getSpriteList()[index]->getName() << endl;
	cout << "Type: " << ss->getSpriteList()[index]->getSpriteType() << endl;	
	cout << "Parent: ";
	if (ss->getSpriteList()[index]->getParent() != NULL)
		cout << ss->getSpriteList()[index]->getParent()->getName() << endl;
	else
		cout << "none" << endl;
	cout << "Parameters: " << endl;
	//puts parameters one by one, name and value
	showParameters(ss->getSpriteList()[index]);
}

void ScriptTester::showSprite(Sprite* s)
{
	cout << "\nSelected Sprite: " << endl;
	cout << "Name: " << s->getName() << endl;
	cout << "Type: " << s->getSpriteType() << endl;
	cout << "Parent: ";
	if (s->getParent() != NULL)
		cout << s->getParent()->getName() << endl;
	else
		cout << "none" << endl;

	cout << "Parameters: " << endl;
	//puts parameters one by one, name and value
	showParameters(s);
}

void ScriptTester::showSpriteList(SpriteSet * ss)
{
	cout << "\nShowing all sprites in sprite list..." << endl;
	cout << "Number of sprites: " << ss->getSpriteList().size() << endl;
	cout << "Number of root sprites: " << ss->getRootSpriteList().size() << endl;
	for (int i = 0; i < ss->getSpriteList().size(); i++)
	{
		showSprite(ss, i);
	}
	cout << "\n\n";
}

void ScriptTester::showSpriteAndChildren(SpriteSet* ss, Sprite * s)
{
		cout << "\nSprite: " << s->getName() << endl;
		cout << "Parent: ";
		if (s->getParent() != NULL)
			cout << s->getParent()->getName() << endl;
		cout << "\nChildren: " << endl;
		for (int i = 0; i < s->getChildren().size();i++)
		{
			cout << s->getChildren()[i]->getName() << endl;
			if (s->getChildren()[i]->getChildren().size() != NULL)//that is, if the child has children
				showSpriteAndChildren(ss, s->getChildren()[i]);//shows children of child(and so on and so forth)
		}
}

void ScriptTester::showSpriteParentTree(SpriteSet * ss)
{
	for (int i = 0; i < ss->getSpriteList().size(); i++)
	{
		//shows sprites and their children, one by one
		showSpriteAndChildren(ss, ss->getSpriteList()[i]);
	}
}

void ScriptTester::showRootSprites(SpriteSet * ss)
{
	cout << "\nRoot Sprite list: " << endl;
	for (int i = 0; i < ss->getRootSpriteList().size(); i++)
	{
		cout << ss->getRootSpriteList()[i]->getName() << endl;

	}
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

void ScriptTester::showMapCharacter(MapCharacter mc)
{
	cout << "Character: " << mc.getMapChar() << endl;
	cout << "Associated sprites: ";
	for (int i = 0; i < mc.getAssociatedSprites().size(); i++)
	{
		cout << mc.getAssociatedSprites()[i] << " ";
	}
	cout << endl;
}

void ScriptTester::showLevelMapping(LevelMapping * lm)
{
	//shows all existing map characters in the levelMapping
	cout << "Characters: " << endl;
	for (int i = 0; i < lm->getCharacterList().size(); i++)
	{
		cout << "\nChar " << i + 1 << ": \n";
		showMapCharacter(lm->getCharacterList()[i]);
	}
	cout << "\n\n";

}

void ScriptTester::showMap(LevelMapping * lm)
{
	cout << "Map: " << endl;
	for (int i = 0; i < lm->getMap().size(); i++)
	{
		cout << "Line "<<i+1<<": "<< lm->getMap()[i] << endl;
	}
}

void ScriptTester::showParameters(Sprite* s)
{
	for (int j = 0; j < s->getParameterList().size(); j++)
	{
		cout << "Parameter " << (j + 1) << endl;
		cout << "Name: " << s->getParameterList()[j].getParameterName() << endl;
		cout << "Value: " << s->getParameterList()[j].getParameterValue() << endl;

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

void ScriptTester::showGlobalParameters(GlobalGameParameters * ggp)
{
	for (int j = 0; j < ggp->getParameterList().size(); j++)
	{
		cout << "Parameter " << (j + 1) << endl;
		cout << "Name: " << ggp->getParameterList()[j].getParameterName() << endl;
		cout << "Value: " << ggp->getParameterList()[j].getParameterValue() << endl;

	}
}

bool ScriptTester::scriptWasLoaded()
{
	return scriptLoaded;
}

void ScriptTester::setScriptLoaded(bool sl)
{
	scriptLoaded = sl;
}

bool ScriptTester::scriptWasWritten()
{
	return scriptWritten;
}

void ScriptTester::setScriptWritten(bool sw)
{
	scriptWritten = sw;
}
