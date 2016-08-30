#pragma once
#include "draggableRectangle.h"
class draggableSprite :
	public draggablerectangle, public ofImage
{
public:
	draggableSprite();
	draggableSprite(int x, int y);
	~draggableSprite();

	ofImage img;

	void loadDraggableImage(string filename) { 
		this->loadImage(filename); 
		this->draggableBounds->width = this->width; 
		this->draggableBounds->height = this->height; 

		img.loadImage(filename);
		


	}
	void draw();
	bool mouseDragged(float x, float y, float width, float height);


};

