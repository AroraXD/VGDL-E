#include "ofMain.h"
#include "ofApp.h"
#include "ScriptTester.h"
#include "InteractionSet.h"
#include "SpriteSet.h"
#include "TerminationSet.h"
#include "VGDLParser.h"




/*For organization's sake, every TODO of the program shall be put in this file, to organize what needs to be done and 
* decently track what has already been accomplished.

TODO: create 'delete' methods for the vectors of objs in the Sprite, Interaction and Termination sets
TODO: create more methods to build the flow of the scriptTester script

//for later on...
TODO: start thinking about Sprite parenting

*/







//========================================================================
int main() {
	ofSetupOpenGL(1024, 768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());


	//this will eventually be used as a text-based tester for the VDGL script builder

	/*
	TerminationSet ts;
	SpriteSet ss;
	InteractionSet is;

	ScriptTester scriptTester;
	scriptTester.runScriptTest(ss, is, ts);
	*/

}
