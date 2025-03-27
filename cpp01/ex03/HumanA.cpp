#include "HumanA.hpp"

HumanA::HumanA(std::string name,Weapon &base_weapon): weapon(base_weapon), name(name)
{
	return ;
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
