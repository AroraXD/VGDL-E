#pragma once
#include <vector>
#include <string>
#include "MapCharacter.h"

/*
*This class will hold the correlation between the sprites and ASCII characters that will represent them in the map building part of the program.
*We will have a list of MapCharacters, similar to 
*/




class LevelMapping
{
public:
	LevelMapping();
	LevelMapping(int width=0, int height=0);
	~LevelMapping();

	std::vector<MapCharacter> getCharacterList();
	void setCharacterList(std::vector<MapCharacter> objList);

	//basic add and delete methods
	bool addCharacterToList(MapCharacter newChar);
	bool addCharacterToList(char newCharacter, std::vector<std::string> newSprites);
	bool deleteCharacterFromList(char charToDelete);
	bool deleteCharacterFromList(MapCharacter charToDelete);


	//modify whole object, modify char and add/delete sprites from object methods

	//modifies character from object at position i on the list
	bool modifyCharacterFromObj(int objIndex, char newChar);

	//adds a sprite to the object at position i
	bool addSpriteToObj(int objIndex, std::string newSprite);

	//delete sprite from list by its name
	bool deleteSpriteFromObj(int objIndex, std::string spriteToDelete);

	//delete sprite from list by its index
	bool deleteSpriteFromObj(int objIndex, int spriteIndex);



	int getWidth();
	void setWidth(int w);
	
	int getHeight();
	void setHeight(int h);

	void createMap();
	void resizeMap(int newWidth, int newHeight);



private:
	//already inherits from ParameterizableObj, so already has a list of Parameters
	std::vector<MapCharacter> characters;//characters that will be used for the level mapping

	int width, height;//will hold the width and height of the ASCII map(necessary?)

	//TODO: how do I save the ASCII map itself?



};

