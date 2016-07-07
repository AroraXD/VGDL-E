#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	font.loadFont("playtime.ttf", 14);

	gui.setup();
	gui.add(game.setup("game", 10, 0, 70));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------wwwwwwwwwww
void ofApp::draw(){

	ofBackground(200, 40, 100);

	font.drawString("Pick a game # using the slider\n\nPress any key to play", 50, 100);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, game*2);

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
