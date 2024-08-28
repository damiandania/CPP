/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:13 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/19 13:00:19 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

/******************************CONSTRUCTORS************************************/

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << this->_name << ": has been created\n";
	return ;
}

HumanB::~HumanB() {
	std::cout << _name << ": just passed away...\n";
	this->_weapon = NULL;
	return ;
}

/******************************SETTERS*****************************************/

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
	std::cout << this->_name << ": received a " << weapon.getType() << "\n";
	return ;
}

/******************************PUBLIC******************************************/

void	HumanB::attack() const {
	if (this->_weapon == NULL) {
		std::cout 	<< this->_name << ": attacks with their fists\n";
	}
	else {
		std::cout 	<< this->_name << ": attacks with their "
					<< this->_weapon->getType() << "\n";
	}
}
