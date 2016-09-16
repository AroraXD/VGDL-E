#include "MapTile.h"


MapTile::MapTile()
{
	posX = 0;
	posY = 0;
	SpriteLoaded = false;
	name = "blank";
}


MapTile::~MapTile()
{
}
 

MapTile::MapTile(int x, int y, ofImage s): posX(x), posY(y), sprite(s)
{
	SpriteLoaded = true;
	//sprite->getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
	sprite.resize(width * 2, height * 2);
}

MapTile::MapTile(int x, int y, int w, int h) : posX(x), posY(y), width(w), height(h)
{
	SpriteLoaded = false;
}

void MapTile::draw()
{
	if(SpriteLoaded)
	{ 
		//todo make sure it is centered
		ofSetColor(255);
		sprite.draw(posX-width,posY-height);
	}
	else
	{
		ofSetColor(200,200);
		ofDrawCircle(posX, posY, MIN(width, height));
	}
}

void MapTile::setSprite(ofImage s)
{
	sprite = s; 
	//sprite->getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
	sprite.resize(width*2,height*2);
}

void MapTile::resize(int w, int h)
{
	width = w;
	height = h;
	sprite.resize(width*2, height*2);
}

string MapTile::getName()
{
	return name;
}

void MapTile::setName(string s)
{
	name = s;
}
