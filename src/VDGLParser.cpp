#include "VDGLParser.h"
#include <fstream>


VDGLParser::VDGLParser(std::string fileName)//filename is VGDL script's name, map's name is filename + 'Map'
{
	//for now, sets the script paths to default(save on C:/)
	setPath("C:/" + fileName + ".txt");
	setLevelPath("C:/" + fileName + "Map.txt");

	//then creates the files themselves
	std::ofstream newFile(getPath());
	std::ofstream newMapFile(getLevelPath());

	//the path will be saved and used in the future



}


VDGLParser::~VDGLParser()
{
}

std::string VDGLParser::getPath()
{
	return scriptPath;
}

void VDGLParser::setPath(std::string newPath)
{
	scriptPath = newPath;
}

std::string VDGLParser::getLevelPath()
{
	return levelScriptPath;
}

void VDGLParser::setLevelPath(std::string newLevelPath)
{
	levelScriptPath = newLevelPath;
}




bool VDGLParser::reloadFile(std::string filePath)
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

bool VDGLParser::writeVGDLScript(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet)
{
	//here is where the action happens
	//The method writes the VGDL script from scratch, so it must place ALL of the necessary things in it

	std::ofstream VGDLScript;
	VGDLScript.open(getPath());

	if (VGDLScript.is_open())
	{
		//does everything

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
			VGDLScript << "\t" + spriteList[i].getName() + " > ";
			for (int j = 0; j < spriteList[i].getSpriteParameters().size(); j++)
			{
				//puts the parameters in order
				VGDLScript << spriteList[i].getSpriteParameters()[j].getParameterName() + "=" + spriteList[i].getSpriteParameters()[j].getParameterValue() + " ";
			}
			//sprite is over, jump line and go to next sprite
			VGDLScript << "\n";

		}
		//APART FROM PARENT SPRITES, SPRITESET CONSTRUCTION IS COMPLETE



		VGDLScript << "\tInteractionSet";

		//now we fill the interactions with the following syntax:
		//	sprite ListOfInteractorSprites > consequence PossibleParameterList
		std::vector<Interaction> interactionList = interactionSet.getInteractionList();

		//for each interaction, write a line
		for (int i = 0; i < interactionList.size(); i++)
		{
			VGDLScript << "\t";
			VGDLScript << "\t"+interactionList[i].getInteractedSprite + " ";
			for (int j = 0; j < interactionList[i].getInteractorSprites().size(); j++)
			{
				//gets each of the current interacted sprite's interactor sprites
				VGDLScript << interactionList[i].getInteractorSprites()[j]+ " ";
			}
			VGDLScript << " > ";
			//now to write the "consequence" and its possible parameters
			VGDLScript << interactionList[i].getInteractionType+" ";
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

		//TODO: complete and TerminationSet, leave LevelMapping for last


		VGDLScript << "\tTerminationSet";

		VGDLScript << "\tLevelMapping";





		//closes it to save it
		VGDLScript.close();
		//returns true at the very end
		return true;
	}

	else
		return false;


}

bool VDGLParser::createVGDLScript(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet)
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
