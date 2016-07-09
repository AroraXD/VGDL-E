#pragma once

#include <string>
#include "SpriteSet.h"
#include "TerminationSet.h"



class VDGLParser
{
public:
	VDGLParser();
	~VDGLParser();

	std::string getPath();
	void setPath(std::string newPath);

	std::string getLevelPath();
	void setLevelPath(std::string newLevelPath);

	void createVGDLScript(std::string path, SpriteSet spriteSet, TerminationSet terminationSet);//creates a text file in the path indicated, and builds the VGDL script in it

private:
	std::string scriptPath;//holds the path to the VGDL script
	std::string levelScriptPath;//holds the path to the VGDL level script

};

