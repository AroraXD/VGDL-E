#include "VDGLParser.h"



VDGLParser::VDGLParser()
{
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

void VDGLParser::createVGDLScript(std::string path, SpriteSet spriteSet, TerminationSet terminationSet)
{
}
