#pragma once

#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator
{
private:
	std::vector<ATarget*> _targets;

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(const ATarget*);
	void forgetTargetType(const std::string &);
	ATarget* createTarget(const std::string &);
};
