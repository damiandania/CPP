/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/20 12:30:38 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/******************************CONSTRUCTORS************************************/

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << BLUE "[ScavTrap] " << this->_name
		<< " constructor default is called" RESET "\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << BLUE "[ScavTrap] " << this->_name << " constructor is called"
		RESET "\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & source) : ClapTrap() {
	std::cout << BLUE "[ScavTrap] " << source.getName() << " copy is called"
		RESET "\n";
	*this = source;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << BLUE "[ScavTrap] " << this->_name << " destructor is called"
		RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

ScavTrap &	ScavTrap::operator=(ScavTrap const & source) {
	if (this != &source) {
		std::cout << BLUE "[ScavTrap] Assignment operator is called, now "
			<< this->_name << " is " << source.getName() << RESET "\n";
		this->_name = source.getName();
		this->_hitPoints = source.getHitPoints();
		this->_energyPoints = source.getEnergyPoints();
		this->_attackDamage = source.getAttackDamage();
	}
	return (*this);
}

/******************************PUBLIC******************************************/

void	ScavTrap::attack(std::string const & target) {
	if (this->_energyPoints > 0) {
		std::cout << YELLOW "[ScavTrap] " << this->_name << " attacks "
			<< target << " like a crazy, causing " << this->_attackDamage
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

void	ScavTrap::guardGate(void) {
	std::cout << MAGENTA "[ScavTrap] " << this->_name
		<< " is now in Gate keeper mode" RESET "\n";
	return ;
}
