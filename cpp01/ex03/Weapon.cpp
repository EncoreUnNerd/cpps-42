#include "Weapon.hpp"

std::string const &Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string new_type)
{
	type = new_type;
}

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string base_type) : type(base_type)
{
	return ;
}
