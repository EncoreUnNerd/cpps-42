#include "Weapon.hpp"

std::string const &Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string new_type)
{
	type = new_type;
}
