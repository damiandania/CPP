/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:13 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/18 16:09:05 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

/******************************CONSTRUCTORS************************************/

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon){
	std::cout << this->_name << ": has been created\n";
	std::cout << this->_name << ": received a " << _weapon.getType() << "\n";
	return ;
}

HumanA::~HumanA() {
	std::cout << _name << ": just passed away...\n";
	return ;
}

/******************************PUBLIC******************************************/

void	HumanA::attack() const {
	std::cout << this->_name << ": attacks with their "
		<< this->_weapon.getType() << "\n";
}
