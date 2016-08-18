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
}

MapTile::MapTile(int x, int y) : posX(x), posY(y)
{
	SpriteLoaded = false;
}

void MapTile::draw()
{
	if(SpriteLoaded)
	{ 
		sprite->draw(posX,posY);
	}
}

void MapTile::setSprite(ofImage* s)
{
	sprite = s;
}