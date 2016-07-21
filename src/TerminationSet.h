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

	bool deleteTermination(Termination deletedTermination);
	bool deleteTermination(int index);//delete termination based on the index of the termination in the list

private:
	std::vector<Termination> terminationList;

	std::vector<std::string> terminationTypeList = { "SpriteCounter","MultiSpriteCounter","TimeoutScoreCount" };
	std::vector<std::string> terminationParameterList = { "stype","limit","stype1","stype2" };

};

