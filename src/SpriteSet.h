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

	std::list<Sprite> getSpriteList();
	void addSpriteInList(Sprite newS);

	std::vector<std::string> getSpriteTypeList();


private:
	std::list<Sprite> spriteList;//holds list of sprites. Needs to be dynamic, right?
	std::vector<std::string> spriteTypeList = {"MovingAvatar", "HorizontalAvatar", "OngoingAvatar","OngoingTurningAvatar",//0-3
									  "MissileAvatar","OrientedAvatar","ShootAvatar","FlakAvatar",//4-7, here ends Avatar Sprites section
									  "Immovable","Passive","Flicker","OrientedFlicker",//8-11, in 8 starts "Other Sprites" section
									  "Missile","RandomMissile","RandomNPC","Chaser",//12-15
									  "Fleeing","AlternateChaser","RandomAltChaser","SpawnPoint",//16-19
									  "Bomber","RandomBomber","BomberRandomMissile","Spreader",//20-23
									  "Door","Portal","Resource"//24-26
									};//list all possible sprite types

	std::vector<std::string> colorList = { "BLUE", "DARKBLUE","RED","YELLOW","ORANGE","WHITE" };

	std::vector<std::string> parameterTypeList = { "shrinkfactor","invisible","hidden","img", //0-3
										"color","singleton","cooldown","speed", //4-7
										"orientation","rotateInPlace"//8-9 
										};//list of possible parameter types
};

#endif /* SPRITESET_H_ */
