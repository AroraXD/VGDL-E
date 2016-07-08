/*
 * Sprite.h
 *
 *  Created on: Jul 7, 2016
 *      Author: BConfessor
 */

#ifndef SPRITE_H_
#define SPRITE_H_
#include <string>
#include <list>
#include <vector>
#include "SpriteParameter.h"


/*Sprite is a class that holds a single instance of a Sprite object, with all its possible variables, like
*name, its spriteType,
*/

class Sprite {
public:
	Sprite(std::string newName, std::string stype);
	Sprite(std::string newName, std::string stype, std::list<SpriteParameter> paramList);

	virtual ~Sprite();


	std::string getName();
	void setName(std::string newName);

	std::string getSpriteType();
	void setSpriteType(std::string newstype);

	std::vector<SpriteParameter> getSpriteParameters();
	void addParameter(SpriteParameter newParameter);
	

private:
	std::string name;
	std::string spriteType;//sprite type of this particular sprite

	std::vector<SpriteParameter> parameterList;//one sprite can have a lot of parameters



};

#endif /* SPRITE_H_ */
