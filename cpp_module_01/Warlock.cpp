#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done.\n";
}

const std::string &Warlock::getName() const
{
	return (_name);
}

const std::string &Warlock::getTitle() const
{
	return (_title);
}

void Warlock::setTitle(const std::string &title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void Warlock::learnSpell(ASpell *spell)
{
	std::vector<ASpell*>::iterator i;
	for (i = _book.begin(); i < _book.end(); i++)
	{
		if ((*i)->getName() == spell->getName())
			return;
	}
	_book.push_back(spell->clone());
}

void Warlock::forgetSpell(const std::string &spell)
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

void Warlock::launchSpell(const std::string &spell, ATarget &target) const
{
	std::vector<ASpell*>::const_iterator i;
	for (i = _book.begin(); i < _book.end(); i++)
	{
		if ((*i)->getName() == spell)
		{
			(*i)->launch(target);
		}
	}
}

