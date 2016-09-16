#include "SpriteManager.h"



SpriteManager::SpriteManager()
{
	//load all sprites

	//code from http://openframeworks.cc/documentation/utils/ofDirectory/
	//some path, may be absolute or relative to bin/data
	string path = "sprites";
	ofDirectory dir(path);
	//only show png files
	dir.allowExt("png");
	//populate the directory object
	dir.listDir();

	//go through and loads all the sprites
	for (int i = 0; i < dir.size(); i++) {
		//ofLogNotice(dir.getPath(i));
		sprites.push_back(draggableSprite(0,0));
		sprites[i].loadDraggableImage(dir.getPath(i));
		sprites[i].setName(dir.getPath(i).erase(0,8));
		//cout << sprites[i].getName();
	}
}


SpriteManager::~SpriteManager()
{

}

void SpriteManager::draw() {

	//backgroung box
	ofSetColor(200, 200);
	ofDrawRectangle(ofGetWidth() * 0, ofGetHeight()*0.8, ofGetWidth(), ofGetHeight()*0.2);

	//display sprites
	int x = -10;
	int y = ofGetHeight()*0.8 + 5;
	for (int i = 0; i < sprites.size(); i++)
	{
		
		if (x > ofGetWidth() - 50)
		{
			x = -10;
			y = y + 25;
		}
		x = x + 25;

		sprites[i].draw(x,y);

		if (sprites[i].isBeingDragged)
		{
			sprites[i].draw();
		}
	}

}

void SpriteManager::mouseDragged(int x, int y)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i].mouseDragged(x,y,50,50);
	}
}

void SpriteManager::mousePressed(int x, int y, int button) {

	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i].mousePressed(x, y, button);
	}
}

ofImage SpriteManager::getCurrentSpriteImg() {

	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i].isBeingDragged)
			return sprites[i].img;
	}
	return NULL;
}

bool SpriteManager::isASpriteSelected()
{
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i].isBeingDragged)
			return true;
	}
	return false;
}
