#include "draggableSprite.h"



draggableSprite::draggableSprite()
{

}

draggableSprite::draggableSprite(int x, int y)
{
	posX = x;
	posY = y;
	draggableBounds->setPosition(posX, posY);

}

draggableSprite::~draggableSprite()
{
}


void draggableSprite::draw()
{
	ofImage::draw(posX,posY);
}

void draggableSprite::drawAtMouse() { 
	ofImage::draw(int(ofGetMouseX),int(ofGetMouseY));
}

void draggableSprite::draw(int x, int y)
{
	ofImage::draw(x, y);
	if(!isBeingDragged)
	{	
	draggableBounds->setPosition(posX, posY);
	posX = x;
	posY = y;
	}
}

bool draggableSprite::mouseDragged(float x, float y, float width, float height) {

	if (isBeingDragged)
	{
		//ofImage::resize(int(width), int(height));

		return draggablerectangle::mouseDragged(x, y);
	}
	else
		return false;
}


void draggableSprite::setName(string n)
{
	name = n;
}

string draggableSprite::getName() {
	return name;
}
