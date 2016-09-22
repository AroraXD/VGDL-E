#include "ofMain.h"
#include "ofApp.h"
#include "ScriptTester.h"
#include "InteractionSet.h"
#include "SpriteSet.h"
#include "TerminationSet.h"
#include "LevelMapping.h"
#include "GlobalGameParameters.h"
#include "VGDLParser.h"




/*For organization's sake, every TODO of the program shall be put in this file, to organize what needs to be done and 
* decently track what has already been accomplished.

TODO: create 'delete' methods for the vectors of objs in the Sprite, Interaction and Termination sets(DONE)
TODO: create 'deleteByName' methods for the vectors of objs in the Sprite(make it a boolean)(DONE)
TODO: create 'add' and 'delete' methods in scriptTester and fill them out(DONE, need tests)
TODO: fix fstream VGDL builder that's not creating the document for some reason(DONE)
TODO: add a "modify object" option to the Sprite, Termination, Interaction menus(to add/remove parameters and etc after creation)(DONE)
TODO: make operator= for all 3 main objects, to make life easier(OPERATOR= DONE)
TODO: Finish 'modify' methods in script tester(DONE, NEEDS TESTING)
TODO: make a method to display all parenting and children(DONE)
TODO: fix possible problem with ofstream giving runtime error(fixed it)
TODO: start thinking about Sprite parenting(DONE)
TODO: fix Modify and Delete Sprite methods(DONE)

TODO: figure out how to allow VGDL docs to be created anywhere within user's disk(BEING DONE, GOTTA FIX IT)
TODO: Make LevelMapping and GlobalParameters classes(DONE)
TODO: Create validation for avatar and non-avatar map character(check letter case)
TODO: Start "read VGDL" method

TODO: Find out how the apparently default 'w' and ' ' map characters work, maybe implement them from the beginning on the background(as in, they are valid, they just don't show anywhere)(DONE)
TODO: Fix the global game params, which aren't being written in the script(DONE)
TODO: Learn how to use the ofxDatGui library so it can be properly used by all the sets
//for later on...
TODO: check syntax rules for capitalized letters, create method for that in Manager script to (de)capitalize an input when needed.(METHODS CREATED, NEED TO PUT THEM IN CORRECT PLACES)
*/




//========================================================================
int main() {
	
	TerminationSet ts;
	SpriteSet ss;
	InteractionSet is;
	LevelMapping lm(0,0);
	GlobalGameParameters ggp;

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

	//uncomment the following two lines if you wish to open the OpenFrameworks windows
	ofSetupOpenGL(1224, 868, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp(new ofApp());


	//this will eventually be used as a text-based tester for the VDGL script builder
	//comment the following 2 lines if you want to disable the console-based script testing


	//ScriptTester scriptTester;
	//scriptTester.runScriptTest(ss, is, ts,lm,ggp);
	

}
