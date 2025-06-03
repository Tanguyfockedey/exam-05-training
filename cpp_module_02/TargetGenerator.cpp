#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	std::vector<ATarget*>::iterator i;
	for (i = _targets.begin(); i < _targets.end(); i++)
		delete *i;
	_targets.clear();
}

void TargetGenerator::learnTargetType(const ATarget* target)
{
	std::vector<ATarget*>::iterator i;
	for (i = _targets.begin(); i < _targets.end(); i++)
	{
		if ((*i)->getType() == target->getType())
			return;
	}
	_targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const std::string &type)
{
	std::vector<ATarget*>::iterator i;
	for (i = _targets.begin(); i < _targets.end(); i++)
	{
		if ((*i)->getType() == type)
		{
			delete *i;
			_targets.erase(i);
		}
	}
}

ATarget* TargetGenerator::createTarget(const std::string &type)
{
	std::vector<ATarget*>::iterator i;
	for (i = _targets.begin(); i < _targets.end(); i++)
	{
		if ((*i)->getType() == type)
			return ((*i)->clone());
	}
	return NULL;
}
