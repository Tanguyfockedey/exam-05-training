#pragma once
#include <string>
#include <vector>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::vector<ASpell*> _book;

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(const ASpell*);
		void forgetSpell(const std::string &);
		ASpell* createSpell(const std::string &);
};
