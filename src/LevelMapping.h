#pragma once
#include <vector>
#include <string>

/*
*This class will hold the correlation between the sprites and ASCII characters that will represent them in the map building part of the program.
*Since it's pretty much a "name-value" relationship, we can use the Parameter class to create a list of these correlations, just like we 
*use it to hold parameters for the Sprite, Interaction and Termination sets.
*/

struct Object
{
	char mapCharacter;//The character that'll be used to represent the sprites on the map.
	std::vector<std::string> sprites;//The sprite(s) that mapCharacter maps to.

};

class LevelMapping
{
public:
	LevelMapping();
	~LevelMapping();

	std::vector<Object> getCharacterList();
	void setCharacterList(std::vector<Object> objList);
	bool addCharacterToList(Object newChar);
	bool addCharacterToList(char newCharacter, std::vector<std::string> newSprites);
	bool deleteCharacterFromList(char charToDelete);
	bool deleteCharacterFromList(Object charToDelete);



	int getWidth();
	void setWidth(int w);
	
	int getHeight();
	void setHeight(int h);




private:
	//already inherits from ParameterizableObj, so already has a list of Parameters
	std::vector<Object> characters;//characters that will be used for the level mapping

	int width, height;//will hold the width and height of the ASCII map(necessary?)

	//TODO: how do I save the ASCII map itself?



};

