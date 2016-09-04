#include <vector>
#include <string>

#pragma once


/*
*The mapCharacter class holds one map character, i.e., one char variable a list of names of sprites that will be associated with that character

*/

class MapCharacter
{
public:
	MapCharacter();
	MapCharacter(char newC, std::vector<std::string> newS);
	~MapCharacter();

	char getMapChar();
	void setMapChar(char newC);


	std::vector<std::string> getAssociatedSprites();
	void setAssociatedSprites(std::vector<std::string> newAssSpriteList);
	bool addAssociatedSprite(std::string newSprite);
	bool modifyAssociatedSprite(int spriteIndex, std::string newSprite);//changes the sprite at position i to the newSprite given
	bool deleteAssociatedSprite(std::string spriteToDelete); //deletes sprite by its name
	bool deleteAssociatedSprite(int spriteIndex);//deletes sprite by its position in the list

	void operator=(MapCharacter mc);
	bool operator==(MapCharacter mc);


private:
	char mapChar;//The character that'll be used to represent the sprites on the map.
	std::vector<std::string> sprites;//The sprite(s) that mapCharacter maps to.
};

