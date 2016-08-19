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

bool draggableSprite::mouseDragged(float x, float y, float width, float height) {

	if (isBeingDragged)
	{
		ofImage::resize(int(width), int(height));

		return draggablerectangle::mouseDragged(x, y);
	}
	else
		return false;
}
