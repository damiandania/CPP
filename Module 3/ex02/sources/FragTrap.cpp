/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/20 12:36:18 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/******************************CONSTRUCTORS************************************/

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << BLUE "[FragTrap] " << this->_name
		<< " constructor default is called" RESET "\n";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << BLUE "[FragTrap] " << this->_name << " constructor is called"
		RESET "\n";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const & source) : ClapTrap() {
	std::cout << BLUE "[ScavTrap] " << source.getName() << " copy is called"
		RESET "\n";
	*this = source;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << BLUE "[FragTrap] " << this->_name << " destructor is called"
		RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

FragTrap &	FragTrap::operator=(FragTrap const & source) {
	if (this != &source) {
		std::cout << BLUE "[FragTrap] Assignment operator is called, now "
			<< this->_name << " is " << source.getName() << RESET "\n";
		this->_name = source.getName();
		this->_hitPoints = source.getHitPoints();
		this->_energyPoints = source.getEnergyPoints();
		this->_attackDamage = source.getAttackDamage();
	}
	return (*this);
}

/******************************PUBLIC******************************************/

void	FragTrap::highFivesGuys(void) {
	std::cout << CYAN "[FragTrap] " << this->_name << " is doing a high five!"
		RESET "\n";
	return ;
}
