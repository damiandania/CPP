/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:11:14 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>

/******************************CONSTRUCTORS************************************/

Harl::Harl(void) {
	return ;
}

Harl::~Harl(void) {
	return ;
}

/******************************PRIVATE*****************************************/

void	Harl::_debug( void ) {
	std::cout << "[ DEBUG ]\nLets look where is the bug...\n";
	return ;
}

void	Harl::_info( void ) {
	std::cout << "[ INFO ]\nMaybe you should do it in this way...\n";
	return ;
}

void	Harl::_warning( void ) {
	std::cout << "[ WARNING ]\nCheck better again the code...\n";
	return ;
}

void	Harl::_error( void ) {
	std::cout << "[ ERROR ]\nSomething went wrong...\n";
	return ;
}

/******************************PUBLIC******************************************/

void	Harl::complain( std::string level ) {
	std::string	complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			index = -1;

	for (int i = 0; i < 4; i++) {
		if (complains[i] == level) {
			index = i;
			break;
		}
	}

	switch (index) {
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
			this->_error();
			break;
		default:
			std::cout << "Complain not found...\n";
	}
	return ;
}
