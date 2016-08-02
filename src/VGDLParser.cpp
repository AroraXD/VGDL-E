#include "VGDLParser.h"
#include <iostream>

VGDLParser::VGDLParser(std::string fileName)//filename is VGDL script's name, map's name is filename + 'Map'
{
	//for now, sets the script paths to default(save on C:/)
	setPath(fileName + ".txt");
	setLevelPath(fileName + "Map.txt");

	//then creates the files themselves
	std::ofstream newFile(getPath());
	std::ofstream newMapFile(getLevelPath());

	//the path will be saved and used in the future



}


VGDLParser::~VGDLParser()
{
}

std::string VGDLParser::getPath()
{
	return scriptPath;
}

void VGDLParser::setPath(std::string newPath)
{
	scriptPath = newPath;
}

std::string VGDLParser::getLevelPath()
{
	return levelScriptPath;
}

void VGDLParser::setLevelPath(std::string newLevelPath)
{
	levelScriptPath = newLevelPath;
}

void VGDLParser::writeSpriteAndChildren(Sprite* s)
{
	//following the syntax, put two tabs to correctly indent the script
	std::ofstream fileToWrite;
	fileToWrite.open(getPath());
	if (fileToWrite.is_open())
		std::cout << "Writing sprites..." << std::endl;
	fileToWrite << "\t";
	//goes through all of the items in the spriteList and puts them in the spriteSet using the VGDL syntax
	fileToWrite << "\t" + s->getName() + " > " + s->getSpriteType() + " ";
	for (int j = 0; j < s->getSpriteParameters().size(); j++)
	{
		//puts the parameters in order
		fileToWrite << s->getSpriteParameters()[j].getParameterName() + "=" + s->getSpriteParameters()[j].getParameterValue() + " ";
	}
	fileToWrite << "\n";
	//TODO: add possible children
	std::cout << "Adding possible children of " << s->getName() << std::endl;
	for (int i = 0; i < s->getChildren().size(); i++)
	{
		fileToWrite << "\t";
		writeSpriteAndChildren(s->getChildren()[i]);//wtf?
		fileToWrite << "\n";
	}
	//sprite is over, jump line and go to next sprite
	fileToWrite<< "\n";
	fileToWrite.close();
}

void VGDLParser::writeTermination(Termination t)
{
	std::ofstream VGDLScript(getPath());
	if (VGDLScript.is_open())
		std::cout << "Writing terminations..." << std::endl;

	//get the termination type
	VGDLScript << "\t";
	VGDLScript << "\t" + t.getTerminationType() + " ";
	//now get each of its possible parameters
	for (int j = 0; j < t.getParameterList().size(); j++)
	{
		VGDLScript << t.getParameterList()[j].getParameterName() + "=" + t.getParameterList()[j].getParameterValue();
		VGDLScript << " ";
	}
	VGDLScript << "\n";

}

void VGDLParser::writeInteraction(Interaction i)
{
	std::ofstream VGDLScript(getPath());
	if (VGDLScript.is_open())
		std::cout << "Writing interactions..." << std::endl;

	VGDLScript << "\t";
	VGDLScript << "\t" + i.getInteractedSprite() + " ";
	for (int j = 0; j < i.getInteractorSprites().size(); j++)
	{
		//gets each of the current interacted sprite's interactor sprites
		VGDLScript << i.getInteractorSprites()[j] + " ";
	}
	VGDLScript << " > ";
	//now to write the "consequence" and its possible parameters
	VGDLScript << i.getInteractionType() + " ";
	for (int j = 0; j < i.getParameterList().size(); j++)
	{
		//write the existing parameters of the consequence
		VGDLScript << i.getParameterList()[j].getParameterName() + "=" + i.getParameterList()[j].getParameterValue();
		VGDLScript << " ";
	}
	//end of this interaction, change line
	VGDLScript << "\n";

}






bool VGDLParser::reloadFile(std::string filePath)
{
	//returns true if reload is successfull
	if (remove(filePath.c_str()) != 0)
	{
		//rebuild fresh files with the existing paths
		std::ofstream newFile(getPath());
		std::ofstream newMapFile(getLevelPath());
		return true;
	}
		
	else
		return false;
}

bool VGDLParser::writeVGDLScript(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet)
{
	//here is where the action happens
	//The method writes the VGDL script from scratch, so it must place ALL of the necessary things in it

	std::ofstream VGDLScript;
	VGDLScript.open(getPath());
	std::cout << "Opening file named "<< getPath() <<"..." << std::endl;
	if (VGDLScript.is_open())
	{
		//does everything
		std::cout << "File Open. Begin writing..." << std::endl;
		VGDLScript << "BasicGame\n";
		VGDLScript << "\tSpriteSet\n";
		//now fill up all the sprites in sprite set following the syntax:
		//	sprite > type ListOfVariables
		//for now we'll ignore parent sprites, as that will put another layer of complexity in the for loops
		std::vector<Sprite*> rootSpriteList = spriteSet.getRootSpriteList();
		for (int i = 0; i < rootSpriteList.size(); i++)
		{
			writeSpriteAndChildren(rootSpriteList[i]);
		}
		//APART FROM PARENT SPRITES, SPRITESET CONSTRUCTION IS COMPLETE



		VGDLScript << "\n\tInteractionSet\n";

		//now we fill the interactions with the following syntax:
		//	sprite ListOfInteractorSprites > consequence PossibleParameterList
		std::vector<Interaction> interactionList = interactionSet.getInteractionList();

		//for each interaction, write a line
		for (int i = 0; i < interactionList.size(); i++)
		{
			writeInteraction(interactionList[i]);
		}
		//believe InteractionSet is complete as well



		VGDLScript << "\n\tTerminationSet\n";
		std::vector<Termination> terminationList = terminationSet.getTerminationList();
		for (int i = 0; i < terminationList.size(); i++)
		{
			writeTermination(terminationList[i]);
		}

		//TODO:leave LevelMapping for last

		VGDLScript << "\n\tLevelMapping\n";





		//closes it to save it
		std::cout << "Writing complete." << std::endl;
		VGDLScript.close();
		//returns true at the very end
		return true;
	}

	else
		return false;


}

bool VGDLParser::createVGDLScript(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet)
{
	//first, we must open the files

	std::ofstream file(getPath());
	std::ofstream levelFile(getLevelPath());
	

	//in order to create it, we erase the file and reconstruct it from scratch so that no info is duplicated


	if (reloadFile(getPath()) && reloadFile(getLevelPath()))
	{
		//reloaded, start writing
		return writeVGDLScript(spriteSet, interactionSet, terminationSet);
	}


	//file reloading failed for some reason
	else
	{
		return false;
	}


}
