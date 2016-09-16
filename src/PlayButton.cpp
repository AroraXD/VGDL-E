#include "PlayButton.h"

bool PlayButton::draw()
{

	ofDrawRectangle(posx, posy, width, height);
	if (ofGetMouseX() < posx + width && ofGetMouseX() > posx && ofGetMouseY() < posy + height && ofGetMouseY() > posy)
	{
		return true;
	}
	else
		return false;
}

//	if (x > draggableBounds->getLeft() && x < draggableBounds->getRight() && y < draggableBounds->getBottom() && y > draggableBounds->getTop())

void PlayButton::resize() {
	int posx = ofGetWidth()*0.4;
	int posy = ofGetHeight()*0.01;
	int widt = ofGetWidth()*0.05;
	int heigh = ofGetHeight()*0.05;
}