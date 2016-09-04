#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "draggableSprite.h"
#include "gridManager.h"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofTrueTypeFont font;
		ofxPanel gui;

		string	text;
		void	typeKey(int key);
		int		position;
		int		cursorx, cursory;
		void	drawText(int x, int y);

		int gridsquarewidth;
		int gridsquareheight;

		ofxIntSlider mapWidth;
		ofxIntSlider mapHeight;

		draggableSprite testSprite = draggableSprite(20,620);

		gridManager grid;
};
