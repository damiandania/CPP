/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/19 20:42:57 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/******************************CONSTRUCTORS************************************/

ClapTrap::ClapTrap(void) : _name("Unknow") , _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << BLUE "ClapTrap " << this->_name
		<< " constructor default is called" RESET "\n";
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name) , _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << BLUE "[ClapTrap] " << this->_name << " constructor is called"
		RESET "\n";
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & source) {
	std::cout << BLUE "[ClapTrap] " << source.getName() << " copy is called..."
		RESET "\n";
	*this = source;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << BLUE "[ClapTrap] " << this->_name << " destructor is called"
		RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

ClapTrap &	ClapTrap::operator=(ClapTrap const & source) {
	if (this != &source) {
		std::cout << BLUE "[ClapTrap] Assignment operator is called, now "
			<< this->_name << " is " << source.getName() << RESET "\n";
		this->_name = source.getName();
		this->_hitPoints = source.getHitPoints();
		this->_energyPoints = source.getEnergyPoints();
		this->_attackDamage = source.getAttackDamage();
	}
	return (*this);
}

/******************************GETTERS*****************************************/

std::string	ClapTrap::getName ( void ) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints ( void ) const {
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints ( void ) const {
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage ( void ) const {
	return (this->_attackDamage);
}

/******************************PUBLIC******************************************/

void	ClapTrap::attack(std::string const & target) {
	if (this->_energyPoints > 0) {
		std::cout << YELLOW "[ClapTrap] " << this->_name << " attacks "
			<< target << ", causing " << this->_attackDamage
			<< " points of damage!" RESET "\n";

		this->_energyPoints--;

		std::cout << "[ClapTrap] " << this->_name << " Hitpoints = "
			<< this->_hitPoints << " / Energy = " << this->_energyPoints << "\n";
	}
	else {
		std::cout << "[ClapTrap] " << this->_name << " doesn't have enough energy\n";
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > 2147483647) {
		std::cout << RED "[ERROR] Wrong damage amount\n";
		return ;
	}
	std::cout << RED "[ClapTrap] " << this->getName() << " takes "
		<< amount << " points of damage" << RESET "\n";

	this->_hitPoints -= amount;

	std::cout << "[ClapTrap] " << this->_name << " Hitpoints = "
		<< this->_hitPoints << " / Energy = " << this->_energyPoints << "\n";
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (amount > 2147483647) {
		std::cout << GREEN "[ERROR] Wrong repair amount\n";
	}
	else if (this->_energyPoints > 0) {
		std::cout << GREEN "[ClapTrap] " << this->getName()
			<< " repairs himself, recovering " << amount << " hit points!"
			RESET "\n";

		this->_hitPoints += amount;
		this->_energyPoints--;

		std::cout << "[ClapTrap] " << this->_name << " Hitpoints = "
			<< this->_hitPoints << " / Energy = " << this->_energyPoints << "\n";
	}
	else {
		std::cout << "[ClapTrap] " << this->_name << " doesn't have enough energy\n";
	}
	return ;
}
