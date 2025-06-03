#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string _type;

	public:
		ATarget();
		ATarget(const std::string &type);
		virtual ~ATarget();

		const std::string &getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell &spell) const;
};
