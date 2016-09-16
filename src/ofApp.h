#pragma once

//frontend
#include "ofMain.h"
#include "ofxGui.h"
#include "gridManager.h"
#include"SpriteManager.h"
#include "Inspector.h"
#include "PlayButton.h"

//backend
#include "ScriptTester.h"
#include "InteractionSet.h"
#include "SpriteSet.h"
#include "TerminationSet.h"
#include "LevelMapping.h"
#include "GlobalGameParameters.h"
#include "VGDLParser.h"
#include "Manager.h"
#include "ScriptTester.h"

class ofApp : public ofBaseApp{

	public:

		ofApp();
		~ofApp();

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

		gridManager grid;

		SpriteManager sprites;

		Inspector inspector;

		PlayButton Play;


		bool isHovered = false;

		//pointers that will hold the necessary backend classes
		SpriteSet* ss;
		TerminationSet* ts;
		InteractionSet* is;
		LevelMapping* lm;
		GlobalGameParameters* ggp;
		Manager* m;
		VGDLParser* vgdlp;
		ScriptTester scriptT;



};
