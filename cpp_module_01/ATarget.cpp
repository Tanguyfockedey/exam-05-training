#include "ATarget.hpp"

ATarget::ATarget(): _type("")
{}

ATarget::ATarget(const std::string &type): _type(type)
{}

ATarget::ATarget(const ATarget &copy)
{
	*this = copy;
}

ATarget::~ATarget()
{}

ATarget &ATarget::operator=(const ATarget &copy)
{
	_type = copy._type;
	return (*this);
}

const std::string &ATarget::getType() const
{
	return (_type);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << _type << " has been " << spell.getEffect() << "!" << std::endl;
}

