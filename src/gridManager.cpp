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

	/*
	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			int tempx = gridPosX + i * (gridWidth / mapWidth);
			int tempy = gridPosY + j * (gridHeight / mapHeight);
			ofDrawCircle(tempx + gridsquarewidth, tempy + gridsquareheight, MIN(gridsquarewidth, gridsquareheight));
		}
	}
	*/
}