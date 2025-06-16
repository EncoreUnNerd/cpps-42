#include "ScavTrap.hpp"

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << name << " has been assembled!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " has been disassembled!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energy_points > 0)
	{
		_energy_points--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " can't attack he has no energy points left!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_attack_damage = scavtrap._attack_damage;
	this->_energy_points = scavtrap._energy_points;
	this->_hit_points = scavtrap._hit_points;
	this->_name = scavtrap._name;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &to_copy) : ClapTrap(to_copy._name)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}