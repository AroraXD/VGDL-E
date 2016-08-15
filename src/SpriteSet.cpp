/*
 * SpriteSet.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: BConfessor
 */

#include "SpriteSet.h"
#include <iostream>

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
	//before deleting the sprite itself, check if it's a root sprite; if so, delete it from root list as well
	if (erasedSprite->getParent() == NULL)
	{
		//delete entry from root list
		for (int i = 0; i < rootSpriteList.size(); i++)
		{
			if (erasedSprite->getName() == rootSpriteList[i]->getName())
			{
				//delete only the entry from the list, the sprite itself will be deleted from the spriteList
				rootSpriteList.erase(rootSpriteList.begin() + i);
				break;//found it, don't need to go through rest of list
			}
		}
	}

	//goes through the sprite list(O(n), I know) and delete the correct sprite
	for (int i = 0; i < spriteList.size(); i++)
	{
		if (spriteList[i] == erasedSprite)
		{
			//delete this sprite
			delete spriteList[i];
			spriteList.erase(spriteList.begin()+i);
			return true;
		}
	}
	return true;
}

bool SpriteSet::deleteSprite(std::string spriteName)
{
	//before deleting the sprite itself, check if it's in the root sprite list; if so, delete it from there as well

	//delete entry from root list
	for (int i = 0; i < rootSpriteList.size(); i++)
	{
		if (spriteName == rootSpriteList[i]->getName())
		{
			//delete only the entry from the list, the sprite itself will be deleted from the spriteList
			rootSpriteList.erase(rootSpriteList.begin() + i);
			break;//found it, don't need to go through rest of list
		}
	}


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
	//index is for sprite list; get sprite parent from there, do the check for root sprite status
	//before deleting the sprite itself, check if it's a root sprite; if so, delete it from root list as well
	if (spriteList[index]->getParent() == NULL)
	{
		//delete entry from root list
		for (int i = 0; i < rootSpriteList.size(); i++)
		{
			if (spriteList[index]->getName() == rootSpriteList[i]->getName())
			{
				//delete only the entry from the list, the sprite itself will be deleted from the spriteList
				rootSpriteList.erase(rootSpriteList.begin() + i);
				break;//found it, don't need to go through rest of list
			}
		}
	}


	if (index <= spriteList.size() - 1)
	{
		//delete this sprite(obj, then pointer)
		delete spriteList[index];
		spriteList.erase(spriteList.begin() + index);
		return true;
	}
	return false;
}

//don't think I need this anymore, now it's a pointer, so if it erases, the same sprite dies
void SpriteSet::modifySprite(Sprite* newSprite, int index)
{
	//erases old sprite, sets the pointer to the new one
	std::cout << "Saving new sprite at position " << index << std::endl;
	std::cout << "Size of spriteList: " << spriteList.size() << std::endl;
	std::cout << "Name of sprite to delete: " << spriteList[index]->getName();
	delete spriteList[index];
	this->spriteList[index] = newSprite;
	std::cout << "Saved" << std::endl;
}

void SpriteSet::addRootSprite(Sprite* rSprite)
{
	rootSpriteList.push_back(rSprite);
}

bool SpriteSet::removeRootSprite(Sprite * rSprite)
{
	for (int i = 0; i < rootSpriteList.size(); i++)
	{
		//check by name, no chance of mixup over pointers
		if (rootSpriteList[i]->getName() == rSprite->getName())
		{
			//delete rootSpriteList[i];
			rootSpriteList.erase(rootSpriteList.begin() + i);
			return true;
		}

	}
	//else, deletion failed
	return false;
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

	//if the child sprite's old parent was null, then now the child sprite is no longer a root sprite, need to fix that
	
	//since we're getting from index, new parent will always exist

	childSprite->setHasParent(true);
	//new parent isn't null, so must take away childSprite from rootSpriteList(if it's there)
	if (childSprite->getParent() == NULL)
	{
		std::cout << "Sprite now has parent, removing from root sprite list " << std::endl;
		removeRootSprite(childSprite);
	}

	//proceeds to add child to parent
	spriteList[parentIndex]->addChild(childSprite);
	//now, adds parent to child
	childSprite->setParent(spriteList[parentIndex]);
	childSprite->setHasParent(true);
	return true;

}

bool SpriteSet::addChildToSprite(Sprite * parentSprite, Sprite * childSprite)
{
	//adds childSprite as a child of parent(if it's not already) and adds parent as parent of childSprite


	//if new parent is null, sprite has no more parent
	if (parentSprite == NULL)
	{
		std::cout << "Null New Parent" << std::endl;
		//this means child sprite is a root sprite; if it's not already on the root list, add it there
		if (childSprite->spriteHasParent())//had a parent before, that means it has to become a root sprite
			addRootSprite(childSprite);
		childSprite->setHasParent(false);
	}
	else
	{
		//checks if they are already related
		if (childSprite->isAChildOf(parentSprite))
			return false;//failed to add child because it was already a child of the parent

		childSprite->setHasParent(true);
		//new parent isn't null, so must take away childSprite from rootSpriteList
		std::cout << "Sprite now has parent, removing from root sprite list " << std::endl;
		removeRootSprite(childSprite);

	}


	//proceeds to add child to parent(if child ain't null)
	if (childSprite != NULL)
	{
		//parent sprite can only receive a child if parent sprite exists;
		//otherwise, just add(null)parent to child
		if(parentSprite!=NULL)
			parentSprite->addChild(childSprite);
		//now, adds parent to child
		childSprite->setParent(parentSprite);
		return true;
	}
	return false;
}

bool SpriteSet::changeParenthood(Sprite * oldParent, Sprite * newParent, Sprite * childSprite)
{
	std::cout << "Entering on pointer change" << std::endl;

	//basically, delete the child in the old sprite(if it isn't null parent) and add it to new parent
	if (oldParent != NULL && deleteChild(oldParent, childSprite) && addChildToSprite(newParent, childSprite))
	{
		std::cout << "Worked 1" << std::endl;
		return true;
	}
	else if (oldParent == NULL && addChildToSprite(newParent,childSprite))
	{
		std::cout << "Worked 2" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Something went wrong" << std::endl;
		return false;
	}


}

bool SpriteSet::changeParentHood(Sprite * oldParent, int newParentIndex, Sprite * childSprite)
{

	//basically, delete the child in the old sprite(if it isn't null parent) and add it to new parent
	if (oldParent != NULL && deleteChild(oldParent, childSprite) && addChildToSprite(newParentIndex, childSprite))
		return true;
	else if (oldParent == NULL && addChildToSprite(newParentIndex, childSprite))
	{
		std::cout << "Old parent was null, added child nicely" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Something went wrong" << std::endl;
		return false;
	}
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

	return parentSprite->deleteChild(childSprite);

	/*
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
	return false;*/
}




