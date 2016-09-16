#pragma once

#include <string>
#include <vector>
#include "MapTile.h"



#include "SpriteSet.h"
#include "TerminationSet.h"
#include "InteractionSet.h"
#include "LevelMapping.h"


/*The manager class will be used for miscellaneous functions, like transforming diferent variables into strings so they can be more easily placed in the VGDL script
* It will also be used for compatibility check between sprite types and parameters, whether a parameter has an acceptable value, whether the given sprite type demands specific params, etc

*/


class Manager
{
public:
	Manager();
	~Manager();
	
	static std::string toString(int i);
	static std::string toString(float f);
	static std::string toString(bool b);

	static void capitalizeInitial(std::string input);//capitalizes first letter of the string
	static void decapitalizeInitial(std::string input);//opposite of method above

	static bool isAlphabetic(std::string input);//check if input is alphabetic, i.e., if all chars in it are letters

	//Receives the list of images from the front-end, transforms that into a list of the associated sprites.
	static std::vector<std::string> getSpritesFromImages(std::vector<MapTile> images, SpriteSet* ss);

	//Receives the list of sprites, and returns the characters associated with each sprite.
	static std::vector<char> getCharsFromSprites(std::vector<std::string> sprites, LevelMapping* lm);

	//receives the Image map from the front end, transforms it into a map of ASCII characters, saves it into levelMapping
	static bool buildASCIIMapFromImageMap(std::vector<MapTile> mapImages, SpriteSet* ss, LevelMapping* lm);

};

