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
#include "Parameter.h"


/*Sprite is a class that holds a single instance of a Sprite object, with all its possible variables, like
*name, its spriteType,
*/

class Sprite {
public:
	Sprite(std::string newName, std::string stype, bool hasParent = false, std::string parent = "null");
	Sprite(std::string newName, std::string stype, std::vector<Parameter> paramList, bool hasParent = false, std::string parent = "null");

	virtual ~Sprite();


	std::string getName();
	void setName(std::string newName);

	std::string getSpriteType();
	void setSpriteType(std::string newstype);

	std::vector<Parameter> getSpriteParameters();
	void addParameter(Parameter newParameter);

	std::string getParent();
	void setParent(std::string newParent);

	bool spriteHasParent();
	

private:
	std::string name;
	std::string spriteType;//sprite type of this particular sprite
	
	bool hasParent;//true if sprite is part of a higher sprite class
	std::string parent;


	std::vector<Parameter> parameterList;//one sprite can have a lot of parameters



};

#endif /* SPRITE_H_ */
