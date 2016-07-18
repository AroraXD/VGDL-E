#include "TerminationSet.h"



TerminationSet::TerminationSet()
{
}

TerminationSet::TerminationSet(std::vector<Termination> newTerminationList)
{
	terminationList = newTerminationList;
}


TerminationSet::~TerminationSet()
{
}

std::vector<Termination> TerminationSet::getTerminationList()
{
	return terminationList;
}

void TerminationSet::setTerminationList(std::vector<Termination> newTerminationList)
{
	terminationList = newTerminationList;
}

void TerminationSet::addTermination(Termination newTermination)
{
	terminationList.push_back(newTermination);
}
