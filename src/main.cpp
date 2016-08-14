#include "ofMain.h"
#include "ofApp.h"
#include "ScriptTester.h"
#include "InteractionSet.h"
#include "SpriteSet.h"
#include "TerminationSet.h"
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


TODO: fix Modify and Delete Sprite methods

TODO: figure out how to allow VGDL docs to be created anywhere within user's disk

//for later on...
TODO: check syntax rules for capitalized letters, create method for that in Manager script to (de)capitalize an input when needed.(METHODS CREATED, NEED TO PUT THEM IN CORRECT PLACES)
*/




//========================================================================
int main() {
	
	TerminationSet ts;
	SpriteSet ss;
	InteractionSet is;

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

	//uncomment the following two lines if you wish to open the OF windows
	ofSetupOpenGL(1024, 768, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp(new ofApp());


	//this will eventually be used as a text-based tester for the VDGL script builder
	//comment the following 2 lines if you want to disable the console-based script testing


	ScriptTester scriptTester;
	scriptTester.runScriptTest(ss, is, ts);
	

}
