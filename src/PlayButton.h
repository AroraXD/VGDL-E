#pragma once
#include "ofMain.h"

class PlayButton
{
public:

	PlayButton();

	bool draw(string text);

	int posx = ofGetWidth()*0.4;
	int posy = ofGetHeight()*0.01;
	int width = ofGetWidth()*0.05;
	int height = ofGetHeight()*0.05;

	void resize();

	ofTrueTypeFont font;

};