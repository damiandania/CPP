/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/02/27 18:27:18 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

/******************************CONSTRUCTORS************************************/

Weapon::Weapon(void) {
	setType("Knife");
	return ;
}

Weapon::Weapon(std::string const type) : _type(type) {
	return;
}

Weapon::~Weapon(void) {
	return;
}

/******************************GETTERS*****************************************/

std::string const	&Weapon::getType(void) const {
	return (this->_type);
}

/******************************SETTERS*****************************************/

void	Weapon::setType(std::string const type) {
	std::cout << this->getType() << " has changed to a " << type << "\n";
	this->_type = type;
	return ;
}
