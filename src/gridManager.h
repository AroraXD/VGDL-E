#pragma once
#include "MapTile.h"


class gridManager
{
public:
	gridManager();
	~gridManager();

	void draw();

	vector<MapTile> gridTiles;


	//todo make these not hard coded
	int mapWidth = 10;
	int mapHeight = 10;

	int gridPosX = ofGetWidth()*0.5;
	int gridPosY = ofGetHeight()*0.15;
	int gridWidth = ofGetWidth()*0.49;
	int gridHeight = ofGetHeight()*0.6;

	int gridsquarewidth = gridWidth / mapWidth / 2;
	int gridsquareheight = gridHeight / mapHeight / 2;
	
	//vector<MapTile>* getTiles();

	void setNearestTile(int x, int y, ofImage image);

	void highlightNearestTile(int x, int y);

};
