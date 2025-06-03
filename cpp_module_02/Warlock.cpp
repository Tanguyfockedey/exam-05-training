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
	_book.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &spell)
{
	_book.forgetSpell(spell);
}

void Warlock::launchSpell(const std::string &spell, ATarget &target)
{
	ASpell *spellToLaunch = _book.createSpell(spell);
	if (spellToLaunch)
	{
		spellToLaunch->launch(target);
		delete spellToLaunch;
	}
}
