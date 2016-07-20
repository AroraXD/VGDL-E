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

void TerminationSet::deleteTermination(Termination deletedTermination)
{
	//goes through the sprite list(O(n), I know) and delete the correct sprite
	for (int i = 0; i < terminationList.size(); i++)
	{
		if (terminationList[i] == deletedTermination)
		{
			//delete this sprite
			terminationList.erase(terminationList.begin() + i);
			return;
		}
	}
}
