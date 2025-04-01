#include "ScavTrap.hpp"

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " is now in Gate Keeper mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << name << " has been assembled!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << getName() << " has been disassembled!" << std::endl;
}