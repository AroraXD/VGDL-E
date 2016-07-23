#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	font.loadFont("playtime.ttf", 14);

	gui.setup();
	gui.add(game.setup("game", 10, 0, 70));

	text = "code goes here";
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------wwwwwwwwwww
void ofApp::draw(){

	ofBackground(180, 40, 100);

	ofSetColor(200,200,200,200);


	font.drawString("Pick a game # using the slider\n\nPress any key to play", 10, 100);
	//ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, game*2);

	//draws the gui in the top left
	gui.draw();

	//play button
	ofDrawRectangle(ofGetWidth()*0.4,ofGetHeight()*0.01,ofGetWidth()*0.05,ofGetHeight()*0.05);

	//asset select 
	ofDrawRectangle(ofGetWidth()*0, ofGetHeight()*0.8, ofGetWidth(), ofGetHeight()*0.2);

	//game map/grid
	ofDrawRectangle(ofGetWidth()*0.5, ofGetHeight()*0.1, ofGetWidth()*0.49, ofGetHeight()*0.6);


	//code/flowchart stuff
	ofDrawRectangle(ofGetWidth()*0.01, ofGetHeight()*0.2, ofGetWidth()*0.45, ofGetHeight()*0.55);
	drawText(ofGetWidth()*0.01, ofGetHeight()*0.2);

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

	ofBackground(0);

	int chosenGame = game;

	char numstr[10];
	sprintf(numstr, "%d", chosenGame);
	string sysString = "java -jar vgdll.jar \"";//GOTTA MANUALLY ADD JAVA PATH?
	sysString += numstr;//adds number to string...
	sysString += "\"";
	const char* c = sysString.c_str();//...and need to make string into char* to use with system


	system(c);//actually calls VGDL

} 

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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