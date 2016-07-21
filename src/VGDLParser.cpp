#include "VGDLParser.h"
#include <fstream>
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
		std::vector<Sprite> spriteList = spriteSet.getSpriteList();
		for (int i = 0; i < spriteList.size(); i++)
		{
			//following the syntax, put two tabs to correctly indent the script
			VGDLScript << "\t";
			//goes through all of the items in the spriteList and puts them in the spriteSet using the VGDL syntax
			VGDLScript << "\t" + spriteList[i].getName() + " > " + spriteList[i].getSpriteType() + " ";
			for (int j = 0; j < spriteList[i].getSpriteParameters().size(); j++)
			{
				//puts the parameters in order
				VGDLScript << spriteList[i].getSpriteParameters()[j].getParameterName() + "=" + spriteList[i].getSpriteParameters()[j].getParameterValue() + " ";
			}
			//sprite is over, jump line and go to next sprite
			VGDLScript << "\n";

		}
		//APART FROM PARENT SPRITES, SPRITESET CONSTRUCTION IS COMPLETE



		VGDLScript << "\n\tInteractionSet\n";

		//now we fill the interactions with the following syntax:
		//	sprite ListOfInteractorSprites > consequence PossibleParameterList
		std::vector<Interaction> interactionList = interactionSet.getInteractionList();

		//for each interaction, write a line
		for (int i = 0; i < interactionList.size(); i++)
		{
			VGDLScript << "\t";
			VGDLScript << "\t"+interactionList[i].getInteractedSprite() + " ";
			for (int j = 0; j < interactionList[i].getInteractorSprites().size(); j++)
			{
				//gets each of the current interacted sprite's interactor sprites
				VGDLScript << interactionList[i].getInteractorSprites()[j]+ " ";
			}
			VGDLScript << " > ";
			//now to write the "consequence" and its possible parameters
			VGDLScript << interactionList[i].getInteractionType()+" ";
			for (int j = 0; j < interactionList[i].getParameterList().size(); j++)
			{
				//write the existing parameters of the consequence
				VGDLScript <<interactionList[i].getParameterList()[j].getParameterName()+"="+interactionList[i].getParameterList()[j].getParameterValue();
				VGDLScript << " ";
			}
			//end of this interaction, change line
			VGDLScript << "\n";

		}
		//believe InteractionSet is complete as well



		VGDLScript << "\n\tTerminationSet\n";
		std::vector<Termination> terminationList = terminationSet.getTerminationList();
		for (int i = 0; i < terminationList.size(); i++)
		{
			//get the termination type
			VGDLScript << "\t";
			VGDLScript << "\t" + terminationList[i].getTerminationType() + " ";
			//now get each of its possible parameters
			for (int j = 0; j < terminationList[i].getParameterList().size(); j++)
			{
				VGDLScript << terminationList[i].getParameterList()[j].getParameterName() + "=" + terminationList[i].getParameterList()[j].getParameterValue();
				VGDLScript << " ";
			}
			VGDLScript << "\n";

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
