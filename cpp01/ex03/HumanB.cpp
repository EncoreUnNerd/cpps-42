#include "HumanB.hpp"

void HumanB::attack(void)
{
	if (!weapon)
		std::cout << " attacks with hes bear hands" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}

HumanB::HumanB(std::string name): weapon(NULL), name(name)
{
	return ;
}
