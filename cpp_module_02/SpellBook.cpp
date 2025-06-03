#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	std::vector<ASpell*>::iterator i;
	for (i = _book.begin(); i < _book.end(); i++)
		delete *i;
	_book.clear();
}

void SpellBook::learnSpell(const ASpell* spell)
{
	std::vector<ASpell*>::iterator i;
	for (i = _book.begin(); i < _book.end(); i++)
	{
		if ((*i)->getName() == spell->getName())
			return;
	}
	_book.push_back(spell->clone());
}

void SpellBook::forgetSpell(const std::string &spell)
{
	std::vector<ASpell*>::iterator i;
	for (i = _book.begin(); i < _book.end(); i++)
	{
		if ((*i)->getName() == spell)
		{
			delete *i;
			_book.erase(i);
		}
	}
}

ASpell* SpellBook::createSpell(const std::string &spell)
{
	std::vector<ASpell*>::iterator i;
	for (i = _book.begin(); i < _book.end(); i++)
	{
		if ((*i)->getName() == spell)
			return ((*i)->clone());
	}
	return NULL;
}
