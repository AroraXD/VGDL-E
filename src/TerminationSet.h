#pragma once

#include <string>
#include "Termination.h"

class TerminationSet
{
public:
	TerminationSet();
	TerminationSet(std::vector<Termination> newTerminationList);
	~TerminationSet();

	std::vector<Termination> getTerminationList();
	void setTerminationList(std::vector<Termination> newTerminationList);
	void addTermination(Termination newTermination);
	void deleteTermination(Termination deletedTermination);

private:
	std::vector<Termination> terminationList;

	std::vector<std::string> terminationTypeList = { "SpriteCounter","MultiSpriteCounter","TimeoutScoreCount" };
	std::vector<std::string> terminationParameterList = { "stype","limit","stype1","stype2" };

};

