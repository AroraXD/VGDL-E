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
			break;
		case 2:
			//ask the name of the sprite to be deleted, look it up in the sprite list, return true if found name and deleted it
			break;
		case 3:
			//get sprite list and display it someway nice(create 'display' method around here)
			break;
		case 4:
			cout << "Returning to main menu" << endl;
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
			break;
		case 2:
			//show interaction list, ask for index of interaction to remove, look it up in the interaction list, return true if found and deleted it
			break;
		case 3:
			//get interaction list and display it someway nice(create 'display' method around here)
			break;
		case 4:
			cout << "Returning to main menu" << endl;
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
			break;
		case 2:
			//show termination list, ask for index of termination to remove, look it up in the termination list, return true if found and deleted it
			break;
		case 3:
			//get termination list and display it someway nice(create 'display' method around here)
			break;
		case 4:
			cout << "Returning to main menu" << endl;
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
}

void ScriptTester::showSpriteList(SpriteSet * ss)
{
}

void ScriptTester::showTerminationList(TerminationSet * ts)
{
}

void ScriptTester::showInteractionList(InteractionSet * is)
{
}
