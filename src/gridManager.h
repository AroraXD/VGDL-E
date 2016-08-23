#pragma once
#include "MapTile.h"


class gridManager
{
public:
	gridManager();
	~gridManager();

	void draw();

	vector<MapTile> gridtiles;

	int mapWidth = 10;
	int mapHeight = 10;

	int gridPosX = ofGetWidth()*0.5;
	int gridPosY = ofGetHeight()*0.1;
	int gridWidth = ofGetWidth()*0.49;
	int gridHeight = ofGetHeight()*0.6;

	int gridsquarewidth = gridWidth / mapWidth / 2;
	int gridsquareheight = gridHeight / mapHeight / 2;
	
};

