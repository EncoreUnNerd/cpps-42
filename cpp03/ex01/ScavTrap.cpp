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

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setAttackDamage(scavtrap.getAttackDamage());
	this->setEnergyPoints(scavtrap.getEnergyPoints());
	this->setHitPoints(scavtrap.getHitPoints());
	this->setName(scavtrap.getName());
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &to_copy) : ClapTrap(to_copy.getName())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}