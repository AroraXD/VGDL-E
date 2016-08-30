#include "MapTile.h"


MapTile::MapTile()
{
	posX = 0;
	posY = 0;
	SpriteLoaded = false;
}


MapTile::~MapTile()
{
}


MapTile::MapTile(int x, int y, ofImage* s): posX(x), posY(y), sprite(s)
{
	SpriteLoaded = true;
	sprite->getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
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
		sprite->draw(posX,posY);

	}
	else
	{
		ofDrawCircle(posX, posY, MIN(width, height));
	}
}

void MapTile::setSprite(ofImage* s)
{
	sprite = s;
	sprite->getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
	sprite->resize(width,height);
}

void MapTile::resize(int w, int h)
{
	width = w;
	height = h;
	sprite->resize(width, height);
}