#include "gridManager.h"



gridManager::gridManager()
{
	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			int tempx = gridPosX + i * (gridWidth / mapWidth);
			int tempy = gridPosY + j * (gridHeight / mapHeight);
			gridTiles.push_back(MapTile(tempx+ gridsquarewidth,tempy+ gridsquareheight,gridsquarewidth,gridsquareheight));
		}
	}
}


gridManager::~gridManager()
{

}

void gridManager::draw()
{
	//draws background
	ofDrawRectangle(gridPosX, gridPosY, gridWidth, gridHeight);

	for (int i = 0; i < gridTiles.size(); i++)
	{
		gridTiles[i].draw();
	}
}
/*
vector<MapTile>* gridManager::getTiles() {

	return &gridTiles ;
}
*/

void gridManager::setNearestTile(int x, int y, ofImage image, string name)
{
	int nearestTile = NULL;
	float nearestTileDist = 999;

	for (int i = 0; i < gridTiles.size(); i++)
	{
		if (ofDist(x, y, gridTiles[i].posX, gridTiles[i].posY) < nearestTileDist)
		{
			nearestTile = i;
			nearestTileDist = ofDist(x, y, gridTiles[i].posX, gridTiles[i].posY);
		}
	}

	gridTiles[nearestTile].setSprite(image);
	gridTiles[nearestTile].SpriteLoaded = true;
	gridTiles[nearestTile].setName(name);
}

void gridManager::highlightNearestTile(int x, int y)
{
	int nearestTile = NULL;
	float nearestTileDist = 999;

	for (int i = 0; i < gridTiles.size(); i++)
	{
		if (ofDist(x, y, gridTiles[i].posX, gridTiles[i].posY) < nearestTileDist)
		{
			nearestTile = i;
			nearestTileDist = ofDist(x, y, gridTiles[i].posX, gridTiles[i].posY);
		}
	}
	ofSetColor(25, 100);
	ofDrawCircle(gridTiles[nearestTile].posX, gridTiles[nearestTile].posY, 20);
}

//todo
//make a reize function