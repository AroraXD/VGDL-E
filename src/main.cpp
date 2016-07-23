#include "ofMain.h"
#include "ofApp.h"
#include "ScriptTester.h"
#include "InteractionSet.h"
#include "SpriteSet.h"
#include "TerminationSet.h"
#include "VGDLParser.h"




/*For organization's sake, every TODO of the program shall be put in this file, to organize what needs to be done and 
* decently track what has already been accomplished.

TODO: create 'delete' methods for the vectors of objs in the Sprite, Interaction and Termination sets(DONE, NEEDS TESTING)
TODO: create 'deleteByName' methods for the vectors of objs in the 3 sets above(make it a boolean)(DONE, NEEDS TESTING)
TODO: create 'add' and 'delete' methods in scriptTester and fill them out(HALF DONE)
TODO: fix fstream VGDL builder that's not creating the document for some reason

//for later on...
TODO: start thinking about Sprite parenting

*/







//========================================================================
int main() {


	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

	//uncomment the following two lines if you wish to open the OF windows
	ofSetupOpenGL(1024, 768, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp(new ofApp());


	//this will eventually be used as a text-based tester for the VDGL script builder

	//comment the following 5 lines if you want to disable the console-based script testing
	TerminationSet ts;
	SpriteSet ss;
	InteractionSet is;

	ScriptTester scriptTester;
	scriptTester.runScriptTest(ss, is, ts);
	

}
