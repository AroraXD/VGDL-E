#pragma once

#include <string>
#include "SpriteSet.h"
#include "InteractionSet.h"
#include "TerminationSet.h"



class VGDLParser
{
public:

	VGDLParser(std::string fileName);
	~VGDLParser();

	std::string getPath();
	void setPath(std::string newPath);

	std::string getLevelPath();
	void setLevelPath(std::string newLevelPath);



	bool reloadFile(std::string filePath);
	bool writeVGDLScript(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet);
	bool createVGDLScript(SpriteSet spriteSet, InteractionSet interactionSet, TerminationSet terminationSet);//creates a text file in the path indicated, and builds the VGDL script in it

private:
	std::string scriptPath;//holds the path to the VGDL script
	std::string levelScriptPath;//holds the path to the VGDL level script


};

