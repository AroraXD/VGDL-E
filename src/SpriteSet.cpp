/*
 * SpriteSet.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: BConfessor
 */

#include "SpriteSet.h"

SpriteSet::SpriteSet() {
	// TODO Auto-generated constructor stub

}

SpriteSet::~SpriteSet() {
	// TODO Auto-generated destructor stub
	//since the spriteList vector is now a list of POINTERS, needs to delete all objects 
	for (int i = 0; i<spriteList.size(); i++)
	{
		delete spriteList[i];
	}
}

std::vector<Sprite*> SpriteSet::getSpriteList()
{
	return spriteList;
}

std::vector<Sprite*>* SpriteSet::getSpriteListReference()
{
	return &spriteList;
}

void SpriteSet::addSprite(Sprite* newSprite)
{
	spriteList.push_back(newSprite);
	if (!newSprite->spriteHasParent())
	{
		//also add it to root sprite list
		rootSpriteList.push_back(newSprite);
	}
}

bool SpriteSet::deleteSprite(Sprite* erasedSprite)
{
	//goes through the sprite list(O(n), I know) and delete the correct sprite
	for (int i = 0; i < spriteList.size(); i++)
	{
		if (spriteList[i] == erasedSprite)
		{
			//delete this sprite
			spriteList.erase(spriteList.begin()+i);
			return true;
		}
	}
	return true;
}

bool SpriteSet::deleteSprite(std::string spriteName)
{
	//goes through the sprite list(O(n), I know) and delete the correct sprite
	for (int i = 0; i < spriteList.size(); i++)
	{
		if (spriteList[i]->getName() == spriteName)
		{
			//delete this sprite(obj, then pointer
			delete spriteList[i];
			spriteList.erase(spriteList.begin() + i);
			return true;
		}
	}

	return false;
}

bool SpriteSet::deleteSprite(int index)
{
	if (index <= spriteList.size() - 1)
	{
		//delete this sprite(obj, then pointer
		delete spriteList[index];
		spriteList.erase(spriteList.begin() + index);
		return true;
	}
	return false;
}

void SpriteSet::modifySprite(Sprite* newSprite, int index)
{
	//erases old sprite, sets the pointer to the new one
	delete spriteList[index];
	this->spriteList[index] = newSprite;
}

void SpriteSet::addRootSprite(Sprite* rSprite)
{
	rootSpriteList.push_back(rSprite);
}

std::vector<Sprite*> SpriteSet::getRootSpriteList()
{
	return rootSpriteList;
}

bool SpriteSet::addChildToSprite(int parentIndex, Sprite * childSprite)
{
	//adds childSprite as a child of parent(if it's not already) and adds parent as parent of childSprite
	//checks if they are already related
	if (childSprite->isAChildOf(spriteList[parentIndex]))
		return false;//failed to add child because it was already a child of the parent

	//proceeds to add child to parent
	spriteList[parentIndex]->addChild(childSprite);
	//now, adds parent to child
	childSprite->setParent(spriteList[parentIndex]);
	return true;

}

bool SpriteSet::addChildToSprite(Sprite * parentSprite, Sprite * childSprite)
{
	//adds childSprite as a child of parent(if it's not already) and adds parent as parent of childSprite
	//checks if they are already related
	if (childSprite->isAChildOf(parentSprite))
		return false;//failed to add child because it was already a child of the parent

	//if new parent is null, sprite has no more parent
	if (parentSprite == NULL)
	{
		childSprite->setHasParent(false);
	}
	else
		childSprite->setHasParent(true);

	//proceeds to add child to parent(if that ain't null)
	if (childSprite != NULL)
	{
		parentSprite->addChild(childSprite);
		//now, adds parent to child
		childSprite->setParent(parentSprite);
		return true;
	}
	return false;
}

bool SpriteSet::changeParenthood(Sprite * oldParent, Sprite * newParent, Sprite * childSprite)
{
	//basically, delete the child in the old sprite(if it isn't null parent) and add it to new parent
	if (oldParent != NULL && deleteChild(oldParent, childSprite) && addChildToSprite(newParent, childSprite))
		return true;
	else if (oldParent == NULL && addChildToSprite(newParent,childSprite))
		return true;
	else
		return false;


}

bool SpriteSet::changeParentHood(Sprite * oldParent, int newParentIndex, Sprite * childSprite)
{
	//basically, delete the child in the old sprite(if it isn't null parent) and add it to new parent
	if (oldParent != NULL && deleteChild(oldParent, childSprite) && addChildToSprite(newParentIndex, childSprite))
		return true;
	else if (oldParent == NULL && addChildToSprite(newParentIndex, childSprite))
		return true;
	else
		return false;

}

bool SpriteSet::deleteChild(int parentIndex, Sprite * childSprite)
{
	if (parentIndex < spriteList.size())
	{
		spriteList[parentIndex]->deleteChild(childSprite);
		return true;
	}

	return false;//didn't find the child, so didn't delete
}

bool SpriteSet::deleteChild(Sprite * parentSprite, Sprite * childSprite)
{
	//goes through child list, if found, delete child
	for (int i = 0; i < spriteList.size(); i++)
	{
		if (spriteList[i] == parentSprite)
		{
			//delete
			return deleteChild(i, childSprite);
		}

	}
	//didn't find the child sprite in child list
	return false;
}


std::vector<std::string> SpriteSet::getSpriteTypeList()
{
	return spriteTypeList;
}

std::vector<std::string> SpriteSet::getColorList()
{
	return colorList;
}

std::vector<std::string> SpriteSet::getSpriteParameterList()
{
	return spriteParameterList;
}

