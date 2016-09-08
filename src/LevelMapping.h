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
	
	//returns the character list
	std::vector<MapCharacter> getCharacterList();
	//Sets a whole new character list
	void setCharacterList(std::vector<MapCharacter> objList);
	//Checks if character given is in the character list.
	bool characterIsInList(char characterToCheck);


	//basic add and delete methods
	bool addCharacterToList(MapCharacter newChar);
	bool addCharacterToList(char newCharacter, std::vector<std::string> newSprites);
	bool deleteCharacterFromList(char charToDelete);
	bool deleteCharacterFromList(int charIndex);
	bool deleteCharacterFromList(MapCharacter charToDelete);


	//modify whole object, modify char and add/delete sprites from object methods

	//Modifies whole map character.
	bool modifyWholeObj(int objIndex, MapCharacter newMapChar);

	//modifies character from object at position i on the list
	bool modifyCharacterFromObj(int objIndex, char newChar);

	//adds a sprite to the object at position i
	bool addSpriteToObj(int objIndex, std::string newSprite);

	//delete sprite from list by its name
	bool deleteSpriteFromObj(int objIndex, std::string spriteToDelete);

	//delete sprite from list by its index
	bool deleteSpriteFromObj(int objIndex, int spriteIndex);


	//ASCII map methods

	//Checks if the given line is a valid line(i.e., if all the symbols given are mapped)
	bool isValidMapLine(std::string line);//checks all characters against 



	int getWidth();
	void setWidth(int w);
	
	int getHeight();
	void setHeight(int h);

	void setMap(std::vector<std::string> newMap);//sets the new map
	std::vector<std::string> getMap();//returns a copy of the map
	bool modifyMapLine(int line, std::string newMapLine);//modifies map line for a new map line
	void clearMap();//clears current map vector
	void resizeMap(int newWidth, int newHeight);//clears current map and resizes its values



private:
	//already inherits from ParameterizableObj, so already has a list of Parameters
	std::vector<MapCharacter> characters;//characters that will be used for the level mapping


	std::vector<std::string> map;//holds the map itself; will be a vector of strings which will be organized like a matrix in the end

	int width, height;//will hold the width and height of the ASCII map(necessary?)

	//TODO: how do I save the ASCII map itself?



};

