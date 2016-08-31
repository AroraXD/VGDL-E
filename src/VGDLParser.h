#pragma once

#include <string>
#include "SpriteSet.h"
#include "InteractionSet.h"
#include "TerminationSet.h"
#include <fstream>
#include <windows.h>

/*
 *This class is used to read and write VGDL files; information can be written to a VGDL
 *file based on the values input, and a VGDL can also be read and its contents used to 
 *create a SpriteSet, InteractionSet and TerminationSet classes(to be implemented)
 */

class VGDLParser
{
public:

	VGDLParser(std::string fileName);
	~VGDLParser();

	std::string getPath();
	void setPath(std::string newPath);

	std::string getLevelPath();
	void setLevelPath(std::string newLevelPath);

	std::string getFileName();
	void setFileName(std::string newFName);


	//VGDL Write methods
	void writeSpriteSet(SpriteSet* ss);
	void writeSpriteAndChildren(Sprite* s);
	void writeTerminationSet(TerminationSet ts);
	void writeTermination(Termination t);
	void writeInteractionSet(InteractionSet is);
	void writeInteraction(Interaction i);

	bool reloadFile(std::string filePath);
	bool writeVGDLScript(SpriteSet* spriteSet, InteractionSet interactionSet, TerminationSet terminationSet);
	bool createVGDLScript(SpriteSet* spriteSet, InteractionSet interactionSet, TerminationSet terminationSet);//creates a text file in the path indicated, and builds the VGDL script in it

	//VGDL Read methods
	void readIntoSpriteSet(std::string filePath, SpriteSet* ss);//reads file and writes a SpriteSet based on the contents of it
	void readIntoTerminationSet(std::string filePath, TerminationSet* ts);//same as above, for TerminationSet
	void readIntoInteractionSet(std::string filePath, InteractionSet* is);//same as two above, for InteractionSet
	bool readVGDLFile(std::string filePath);


private:
	std::string scriptPath;//holds the path to the VGDL script
	std::string fileName;
	std::string levelScriptPath;//holds the path to the VGDL level script


};

