#pragma once

#include "ofMain.h"

class draggablerectangle
{
	
protected:
	ofRectangle* draggableBounds;
	bool isBeingDragged;

	bool isHovered(float x, float y);

public:
	draggablerectangle();
	~draggablerectangle();

	int posX;
	int posY;

	virtual void draw() =0;
	bool mouseDragged(float x, float y);
	bool mousePressed(float x, float y, int button);
	
	};

