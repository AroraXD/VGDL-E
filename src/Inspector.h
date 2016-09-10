#pragma once
#include "ofmain.h"

class Inspector
{
public:
	Inspector();
	~Inspector();

	void draw();
	void mousePressed(int x, int y);

	ofTrueTypeFont font;

	int tab = 2; // 0 = sprite,  1 = termination, 2 = interaction
};

