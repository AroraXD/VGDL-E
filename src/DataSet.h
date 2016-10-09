#pragma once
#include <vector>

/*The DataSet class will hold all the lists and possible types the Sprites, Interactions, 
 *Terminations and Parameters might be. It will also (possibly) hold methods to validate which
 *values are valid for each type.
*/




class DataSet
{
public:
	DataSet();
	~DataSet();


	//fixed possible parameter lists, so no "set" needed for them
	std::vector<std::string> getSpriteTypeList();//returns sprite type list; most likely to be used in the GUI for the drop-down menus
	std::vector<std::string> getColorList();//returns possible color list; to be used when parameter is of type COLOR
	std::vector<std::string> getSpriteParameterList();//returns all the possible parameters a sprite can have


	//Interaction methods
	std::vector<std::string> getInteractionTypeList();//gets interaction type list; used for drop down menus in GUI
	std::vector<std::string> getInteractionParametersList();//gets possible parameters list; used for drop down menus in GUI

	//Termination methods
	std::vector<std::string> getTerminationTypeList();
	std::vector<std::string> getTerminationParameterList();


	//validation methods 
	//these methods will run the parameter against a list to see whether the parameter is inside that list

	bool isValidSpriteType(std::string sType);//compares sType to every sprite type to see if it's valid
	bool isValidAvatar(std::string av);//checks if string is a type of avatar sprite
	bool isvalidSpriteParameter(std::string sParameter);
	bool isValidColor(std::string color);

	bool isValidInteractionType(std::string iType);
	bool isValidInteractionParameter(std::string iParam);

	bool isValidTerminationType(std::string tType);
	bool isValidTerminationParameter(std::string tParam);

private:
	//Sprite variables
	std::vector<std::string> spriteTypeList = { "MovingAvatar", "HorizontalAvatar", "OngoingAvatar","OngoingTurningAvatar",//0-3
		"MissileAvatar","OrientedAvatar","ShootAvatar","FlakAvatar",//4-7, here ends Avatar Sprites section
		"Immovable","Passive","Flicker","OrientedFlicker",//8-11, in 8 starts "Other Sprites" section
		"Missile","RandomMissile","RandomNPC","Chaser",//12-15
		"Fleeing","AlternateChaser","RandomAltChaser","SpawnPoint",//16-19
		"Bomber","RandomBomber","BomberRandomMissile","Spreader",//20-23
		"Door","Portal","Resource"//24-26
	};//list all possible sprite types


	std::vector<std::string> spriteParameterList = { "shrinkfactor","invisible","hidden","img", //0-3
		"color","singleton","cooldown","speed", //4-7
		"orientation","rotateInPlace"//8-9 
	};//list of possible parameter types

	std::vector<std::string> colorList = { "BLUE", "DARKBLUE","RED","YELLOW","ORANGE","WHITE" };

	//Interaction variables
	std::vector<std::string> interactionTypeList = { "killSprite", "killIfHasMore","killIfHasLess","killFromAbove","killIfOtherHasMore","transformToSingleton", //0-5, KILL category
		"spawnBehind","spawnIfHasMore","spawnIfHasLess","cloneSprite","transformTo","updateSpawnType","removeScore",//6-12, SPAWN category
		"stepBack","undoAll",//13-14, UNDO category
		"flipDirection","reverseDirection","attractGaze",//15-17, DIRECTION category
		"turnAround","wrapAround","teleportToExit","pullWithIt","bounceForward",//18-22,MOVE category
		"collectResource","changeResource"//23-24, RESOURCE category
	};


	std::vector<std::string> interactionParametersList = { "resource", "limit","stype","stype_other","spawnPoint","value" };


	//Termination variables
	std::vector<std::string> terminationTypeList = { "SpriteCounter","MultiSpriteCounter","TimeoutScoreCount" };
	std::vector<std::string> terminationParameterList = { "stype","limit","stype1","stype2", "stype3", "win" };
};

