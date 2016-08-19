#pragma once
#include "ofMain.h"

class MapTile
{
public:
	MapTile();
	~MapTile();

	MapTile(int x, int y, ofImage* s);
	MapTile(int x, int y);

	int posX;
	int posY;

	ofImage* sprite;

	void draw();

	void setSprite(ofImage* s);

	bool SpriteLoaded; //if the tile currently has a sprite or not
};

