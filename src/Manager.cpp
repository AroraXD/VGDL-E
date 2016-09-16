#include "Manager.h"

#include <ctype.h>


Manager::Manager()
{
}


Manager::~Manager()
{
}

std::string Manager::toString(int i)
{
	return std::to_string(i);
}

std::string Manager::toString(float f)
{
	return std::to_string(f);
}

std::string Manager::toString(bool b)
{
	if (b)
		return "True";//VGDL reads True or False with capitals, look out for that

	return "False";
}

void Manager::capitalizeInitial(std::string input)
{
	input[0] = toupper(input[0]);
}

void Manager::decapitalizeInitial(std::string input)
{
	input[0] = tolower(input[0]);
}

bool Manager::isAlphabetic(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		//if any chars are non-alpha, return false
		if (!isalpha(input[i]))
		{
			return false;
		}
	}
	return true;
}


std::vector<std::string> Manager::getSpritesFromImages(std::vector<MapTile> images, SpriteSet* ss)
{
	//for EACH image in the vector, we will need to check it against the sprites, and get the sprite associated with that img(img or stype?)
	std::vector<std::string> spritesToReturn;
	std::vector<Sprite*> spriteList = ss->getSpriteList();
	bool foundCurrentSprite = false;
	for (int i = 0; i < images.size(); i++)
	{
		//if it's a 'blank' tile, simply put 'blank' in the sprites to return and move on to the next one
		if (images[i].getName() == "blank")
		{
			spritesToReturn.push_back("blank");
			continue;
		}

		for (int j = 0; j < spriteList.size(); j++)
		{
			for (int k = 0; k < spriteList[j]->getParameterList().size(); k++)
			{
				//when it finds the name associated with the sprite's parameter, breaks inner for
				if (images[i].getName() == spriteList[j]->getParameterList()[k].getParameterValue())
				{
					//found associated sprite, push it to list
					spritesToReturn.push_back(spriteList[j]->getName());
					foundCurrentSprite = true;
					break;
				}
			}
			//once it's here, check if it already found associated sprite; if so, can move to next element in images vector
			if (foundCurrentSprite)
			{
				foundCurrentSprite = false;
				break;
			}
		}
		//if it reaches end of sprite list and didn't find the associated sprite, default to a wall(w)
		if (spritesToReturn.size() < i + 1)//after i iteractions, spritesToReturn should have i+1 items;if it doesn't, means it didn't find sprite
		{
			spritesToReturn.push_back("WALL");
		}


	}
	//after this expensive thing....returns vector of sprites

	return spritesToReturn;
}

std::vector<char> Manager::getCharsFromSprites(std::vector<std::string> sprites, LevelMapping* lm)
{
	//receives the sprites in order, must transform them into chars
	std::vector<char> charsToReturn;
	std::vector<MapCharacter> mapchars = lm->getCharacterList();
	bool foundCurrentChar = false;

	for (int i = 0; i < sprites.size(); i++)
	{

		//if the current sprite is a "blank" sprite, associate it with floor(by default, it seems to be ' '... ?) and move on to next one
		if (sprites[i] == "blank")
		{
			charsToReturn.push_back(' ');
			continue;
		}

		//likewise, if it's a WALL sprite, associate it with 'w'
		if (sprites[i]=="WALL")
		{
			charsToReturn.push_back('w');//<<-- looks like Arufonsu-kun OwO
			continue;
		}

		//for each sprite, compare it against every map character
		for (int j = 0; j < mapchars.size(); j++)
		{
			std::vector<std::string> associatedSprites = mapchars[j].getAssociatedSprites();
			//for each map char, compare sprite to each of associated sprites
			for (int k = 0; k < associatedSprites.size(); k++)
			{
				if (sprites[i] == associatedSprites[k])
				{
					foundCurrentChar = true;
					charsToReturn.push_back(mapchars[j].getMapChar());
					break;
				}
			}
			//check if found curent char
			if (foundCurrentChar)
			{
				foundCurrentChar = false;
				break;
			}
		}
	}
	//after expeeeensive operation...return chars


	return charsToReturn;
}



bool Manager::buildASCIIMapFromImageMap(std::vector<MapTile> mapImages, SpriteSet* ss, LevelMapping* lm)
{
	//TODO: Implement

	//getting the parameter, we will find the sprite names, and from that, the associated chars 

	std::vector<char> asciiMap = getCharsFromSprites(getSpritesFromImages(mapImages, ss), lm);

	//now use that to build the map on the LevelMapping
	lm->setMap(asciiMap);


	return true;
}



