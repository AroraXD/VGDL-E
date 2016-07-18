#pragma once

#include <string>
#include <vector>

#include "ParameterizableObj.h"

class Interaction : public ParameterizableObj
{
public:

	Interaction(std::string spriteName, std::vector<std::string> interactorSpritesList);
	Interaction(std::string spriteName, std::vector<std::string> interactorSpritesList, std::vector<Parameter> interactionParameterList);
	~Interaction();

	std::string getInteractedSprite();
	void setInteractedSprite(std::string newInteractedSprite);

	std::string getInteractionType();
	void setInteractionType(std::string newInteractionType);

	std::vector<std::string> getInteractorSprites();
	void setInteractorSprites(std::vector<std::string> newInteractorList);
	void addNewInteractorSprite(std::string newInteractorSprite);

private:
	std::string interactedSprite;//the first sprite, the one that's suffering the action
	std::vector<std::string> interactorSprites; //the sprite( or sprites) that is(are) the doer(s) of the action

	std::string interactionType;//the "consequence" the interactedSprite suffers

};

