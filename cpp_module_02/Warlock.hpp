#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	std::string _name;
	std::string _title;
	SpellBook _book;

	Warlock();
	Warlock(Warlock &copy);
	Warlock &operator=(Warlock &copy);

public:
	Warlock(std::string name, std::string title);
	~Warlock();

	const std::string &getName() const;
	const std::string &getTitle() const;

	void setTitle(const std::string &title);

	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spell);
	void launchSpell(const std::string &spell, ATarget &target);


};

