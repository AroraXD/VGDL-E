#pragma once
#include "ofMain.h"

class MapTile
{
public:
	MapTile();
	~MapTile();

	MapTile(int x, int y, ofImage* s);
	MapTile(int x, int y, int w, int h);

	int posX;
	int posY;

	int height =15;
	int width = 15;

	ofImage* sprite;

	void draw();

	void setSprite(ofImage* s);

	bool SpriteLoaded; //if the tile currently has a sprite or not

	void resize(int w, int h);
};

