#pragma once

#include <draggableSprite.h>


class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	vector<draggableSprite> sprites;

	void draw();

	void mouseDragged(int x, int y);
	void mousePressed(int x, int y, int button);

	ofImage getCurrentSpriteImg();

	bool isASpriteSelected();
};

