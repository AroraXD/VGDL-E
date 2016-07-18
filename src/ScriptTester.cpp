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
	VGDLParser vgdlP("test.txt");

	bool loop = true;
	int choice = 0;
	while (loop)
	{
		cout << "Which main segment would you like to work with now?: \n1)SpriteSet \n2)InteractionSet \n3)TerminationSet";
		cin >> choice;
		switch (choice)
		{
		case 1:
			workWithSpriteSet(spriteSet);
			break;
		case 2:
			workWithInteractionSet(interactionSet);
			break;
		case 3:
			workWithTerminationSet(terminationSet);
			break;
		default:
			cout << "Invalid choice, choose again" << endl;
			break;
		}



	}


}

void ScriptTester::workWithSpriteSet(SpriteSet ss)
{
}

void ScriptTester::workWithInteractionSet(InteractionSet is)
{
}

void ScriptTester::workWithTerminationSet(TerminationSet ts)
{
}
