/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:10:55 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

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
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*funtionPtr[4])(void) = {&Harl::_debug, &Harl::_info,
										 &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*funtionPtr[i])();
			return ;
		}
	}
	std::cout << "Complain not found...\n";
	return ;
}
