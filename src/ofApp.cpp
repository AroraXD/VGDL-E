#include "ofApp.h"


ofApp::ofApp() {
	cout << "Called constructor" << endl;
	//Creates the new Sprite, Termination and Interaction Sets, LevelMapping and GlobalGameParameter objects
	ss = new SpriteSet();
	is = new InteractionSet();
	ts = new TerminationSet();
	lm = new LevelMapping(10,10);
	ggp = new GlobalGameParameters();

	m = new Manager();
	vgdlp = new VGDLParser("integrationTest");

}

ofApp::~ofApp() {
	cout << "Called destructor" << endl;
	delete ss;
	delete is;
	delete ts;
	delete lm;
	delete ggp;

	delete m;
	delete vgdlp;

}



//--------------------------------------------------------------
void ofApp::setup(){
	
	font.loadFont("playtime.ttf", 14);

	gui.setup();
	///	gui.add(game.setup("game", 10, 0, 70));
	gui.add(mapWidth.setup("MapHeight", 10, 1, 20));
	gui.add(mapHeight.setup("MapWidth", 10, 1, 20));


	text = "code goes here";

	//testSprite.getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//-------------------------------------------------------------
void ofApp::draw(){

	ofBackground(180, 40, 100);

	ofSetColor(200,200,200,200);

	//draws the of gui in the top left
	//gui.draw();

	//play button
	//ofDrawRectangle(ofGetWidth()*0.4,ofGetHeight()*0.01,ofGetWidth()*0.05,ofGetHeight()*0.05);

	if (Button.draw("Save"))
	{
		//run the code
		//cout << "Test" << endl;
		//dumbass one-time button
		if (!isHovered)
		{
			isHovered = true;
			//NEVER EEEEEVER AGAIN enter this
			m->buildASCIIMapFromImageMap(grid.gridTiles, ss, lm);
			scriptT.showMap(lm);
			if (vgdlp->createVGDLScript(ss, *is, *ts, *lm, *ggp))
			{
				cout << "Script created!\n" << endl;
			}
			else
				cout << "Failed to create script...for some reason" << endl;
		}
	}

	//game map/grid
	grid.draw();
	
	//code/flowchart stuff
	//inspector
	inspector.draw();
	ofPushMatrix();
	//drawText(ofGetWidth()*0.01, ofGetHeight()*0.2);//todo move text input code into inspector class
	ofPopMatrix();

	//highlights closest gridtile to the mouse
	grid.highlightNearestTile(mouseX, mouseY);

	ofSetColor(255);

	//draws the sprites
	sprites.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	typeKey(key);
}

//todo add tab key support 
void ofApp::typeKey(int key) {
	//add charachter
	if (key >= 32 && key <= 126) {
		text.insert(text.begin() + position, key);
		position++;
	}

	if (key == OF_KEY_RETURN) {
		text.insert(text.begin() + position, '\n');
		position++;
	}

	if (key == OF_KEY_BACKSPACE) {
		if (position>0) {
			text.erase(text.begin() + position - 1);
			--position;
		}
	}

	if (key == OF_KEY_DEL) {
		if (text.size() > position) {
			text.erase(text.begin() + position);
		}
	}

	if (key == OF_KEY_LEFT)
		if (position>0)
			--position;

	if (key == OF_KEY_RIGHT)
		if (position<text.size())
			++position;

	//for multiline:
	cursorx = cursory = 0;
	for (int i = 0; i<position; ++i) {
		if (*(text.begin() + i) == '\n') {
			++cursory;
			cursorx = 0;
		}
		else {
			cursorx++;
		}
	}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){


	//old - used to launch the game examples 
	/*
	ofBackground(0);

	int chosenGame = game;

	char numstr[10];
	sprintf(numstr, "%d", chosenGame);
	string sysString = "java -jar vgdll.jar \"";//GOTTA MANUALLY ADD JAVA PATH?
	sysString += numstr;//adds number to string...
	sysString += "\"";
	const char* c = sysString.c_str();//...and need to make string into char* to use with system

	system(c);//actually calls VGDL
	*/
} 

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

	sprites.mouseDragged(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	sprites.mousePressed(x,y,button);
	inspector.mousePressed(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	if (sprites.isASpriteSelected())
	{
		grid.setNearestTile(x, y, sprites.getCurrentSpriteImg(), sprites.getCurrentSpriteName());
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::drawText(int x,int y) {
	//ofScale(5, 5);
	ofTranslate(x, y+5, 0);

	ofSetColor(10);
	ofDrawBitmapString(text, 10, 10);

	ofPushStyle();
	float timeFrac = 255.0f * sin(3.0f * ofGetElapsedTimef());
	ofSetColor(timeFrac, timeFrac, timeFrac);
	ofSetLineWidth(3.0f);
	ofLine(cursorx * 8 + 10, 13.7*cursory, cursorx * 8 + 10, 10 + 13.7*cursory);
	ofPopStyle();
}