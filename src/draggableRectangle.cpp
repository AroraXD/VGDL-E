#include "draggablerectangle.h"



draggablerectangle::draggablerectangle()
{
	draggableBounds = new ofRectangle;
	draggableBounds->setPosition(posX,posY);
}


draggablerectangle::~draggablerectangle()
{
}

bool draggablerectangle::isHovered(float x, float y) {

	if (x > draggableBounds->getLeft() && x < draggableBounds->getRight() && y < draggableBounds->getBottom() && y > draggableBounds->getTop())
		return true;
	else
		return false;
}

bool draggablerectangle::mouseDragged(float x, float y) 
{
	if (isBeingDragged)
	{
		draggableBounds->setPosition(x,y);
		posX = x;
		posY = y;
		return true;
	}
	else
		return false;
}

bool draggablerectangle::mousePressed(float x, float y, int button)
{
	if (isHovered(x, y))
	{
		isBeingDragged = true;
		return true;
	}
	else {
		isBeingDragged = false;
		return false;
	}
}
