#pragma once
#include "ofMain.h"

class PlayButton
{
public:

	bool draw();

	int posx = ofGetWidth()*0.4;
	int posy = ofGetHeight()*0.01;
	int width = ofGetWidth()*0.05;
	int height = ofGetHeight()*0.05;

	void resize();
};