/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:51:17 by ddania-c          #+#    #+#             */
/*   Updated: 2024/02/21 19:08:11 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/******************************CONSTRUCTORS************************************/

Zombie::Zombie(void) {
	return ;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << this->_name << ": has been created...\n";
	return ;
}

Zombie::~Zombie(void) {
	std::cout << this->_name << ": just die...\n";
	return ;
}

/******************************PUBLIC******************************************/

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}
