#pragma once

#include <string>
#include <vector>

#include "Parameter.h"


class Interaction
{
public:
	Interaction();
	~Interaction();

private:
	std::string interactedSprite;//the first sprite, the one that's suffering the action
	std::vector<std::string> interactorSprites; //the sprite( or sprites) that is(are) the doer(s) of the action

	std::vector<Parameter> parameterList;//list of parameters of the interaction, same kind of generic parameter as SpriteSet

};

