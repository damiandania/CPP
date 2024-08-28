/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/09 00:21:40 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/******************************CONSTRUCTORS************************************/

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
	this->_name = "Default";
	this->ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = FT_HIT_POINTS;
	this->_energyPoints = ST_ENERGY_POINTS;
	this->_attackDamage = FT_ATTACK_DAMAGE;
	std::cout << BLUE "[DiamondTrap] " << this->_name
		<< " constructor default is called" RESET "\n";
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
	ScavTrap(), FragTrap() {
	this->_name = name;
	this->_hitPoints = FT_HIT_POINTS;
	this->_energyPoints = ST_ENERGY_POINTS;
	this->_attackDamage = FT_ATTACK_DAMAGE;
	std::cout << BLUE "[DiamondTrap] " << this->_name << " constructor is called"
		RESET "\n";
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & source) : ClapTrap(), ScavTrap(),
	FragTrap() {
	std::cout << BLUE "[DiamondTrap] copy is called..." RESET "\n";
	*this = source;
	return ;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << BLUE "[DiamondTrap] " << this->_name << " destructor is called"
		RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & source) {
	if (this != &source) {
		std::cout << BLUE "[DiamondTrap] Assignment operator is called, now "
			<< this->_name << " is " << source._name << RESET "\n";
		this->ClapTrap::_name = source.getName();
		this->_name = source._name;
		this->_hitPoints = source.getHitPoints();
		this->_energyPoints = source.getEnergyPoints();
		this->_attackDamage = source.getAttackDamage();
	}
	return (*this);
}

/******************************PUBLIC******************************************/

void	DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << ORANGE "[DiamondTrap] Hello my name is " << this->_name
		<< " and my Clap name is " << ClapTrap::getName() << RESET "\n";
	return ;
}
