/*
 * SpriteSet.h
 *
 *  Created on: Jul 7, 2016
 *      Author: BConfessor
 */
#include "Sprite.h"
#include <list>
#include <vector>

#ifndef SPRITESET_H_
#define SPRITESET_H_

/* SpriteSet holds the types of sprites a Sprite can be, as well as a list of the existing sprites in the program.
 *
 *
 */

class SpriteSet {
public:
	SpriteSet();
	virtual ~SpriteSet();

	std::vector<Sprite*> getSpriteList();//returns sprite list
	std::vector<Sprite*>* getSpriteListReference();//returns a pointer to the spriteList
	void addSprite(Sprite* newSprite);//adds new sprite to the Sprite list
	
	//deletes Sprite from the Sprite list; has to check all, so O(n), but list will be small, so it should be fine
	bool deleteSprite(Sprite* erasedSprite);
	bool deleteSprite(std::string spriteName);//deletes first sprite whose name = parameter
	bool deleteSprite(int index);

	void modifySprite(Sprite* newSprite, int index);//puts newSprite in the position index of the spriteSet

	void addRootSprite(Sprite* rSprite);//adds a root sprite to the root sprite list
	bool removeRootSprite(Sprite* rSprite);//removes a root sprite from the root sprite list
	std::vector<Sprite*> getRootSpriteList();


	//adds, modifies and deletes children from a sprite, given the parent sprite's index
	bool addChildToSprite(int parentIndex, Sprite* childSprite);
	bool addChildToSprite(Sprite* parentSprite, Sprite* childSprite);
	bool changeParenthood(Sprite* oldParent, Sprite* newParent, Sprite* childSprite);
	bool changeParentHood(Sprite* oldParent, int newParentIndex, Sprite* childSprite);
	bool deleteChild(int parentIndex, Sprite* childSprite);
	bool deleteChild(Sprite* parentSprite, Sprite* childSprite);

	//fixed possible parameter lists, so no "set" needed for them
	std::vector<std::string> getSpriteTypeList();//returns sprite type list; most likely to be used in the GUI for the drop-down menus
	std::vector<std::string> getColorList();//returns possible color list; to be used when parameter is of type COLOR
	std::vector<std::string> getSpriteParameterList();//returns all the possible parameters a sprite can have



private:

	//holds list of ALL the sprites. This will make my life easier so that I don't have to worry about creating
	//'new' sprites and dealing with memory leak; this list holds all existing sprites, and the parent-child relationships
	//are dealt in the individual sprites through pointer lists(so that all the actual sprites are only stored in one location)
	std::vector<Sprite*> spriteList;


	//holds a list of pointers to all root sprites, i.e., sprites that do not have parents
	std::vector<Sprite*> rootSpriteList;	


	std::vector<std::string> spriteTypeList = {"MovingAvatar", "HorizontalAvatar", "OngoingAvatar","OngoingTurningAvatar",//0-3
									  "MissileAvatar","OrientedAvatar","ShootAvatar","FlakAvatar",//4-7, here ends Avatar Sprites section
									  "Immovable","Passive","Flicker","OrientedFlicker",//8-11, in 8 starts "Other Sprites" section
									  "Missile","RandomMissile","RandomNPC","Chaser",//12-15
									  "Fleeing","AlternateChaser","RandomAltChaser","SpawnPoint",//16-19
									  "Bomber","RandomBomber","BomberRandomMissile","Spreader",//20-23
									  "Door","Portal","Resource"//24-26
									};//list all possible sprite types

	std::vector<std::string> colorList = { "BLUE", "DARKBLUE","RED","YELLOW","ORANGE","WHITE" };

	std::vector<std::string> spriteParameterList = { "shrinkfactor","invisible","hidden","img", //0-3
										"color","singleton","cooldown","speed", //4-7
										"orientation","rotateInPlace"//8-9 
										};//list of possible parameter types
};

#endif /* SPRITESET_H_ */
