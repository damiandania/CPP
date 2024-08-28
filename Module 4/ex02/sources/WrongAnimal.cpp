/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:39:19 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/16 23:11:03 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/******************************CONSTRUCTORS************************************/

WrongAnimal::WrongAnimal(void) : _type("WrongUnknow") {
	std::cout << BLUE "[WrongAnimal] constructor default is called" RESET "\n";
	return ;
}

WrongAnimal::WrongAnimal(std::string const & type) : _type(type) {
	std::cout << BLUE "[WrongAnimal] constructor is called" RESET "\n";
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & source) {
	std::cout << BLUE "[WrongAnimal] copy is called" RESET "\n";
	*this = source;
	return ;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << BLUE "[WrongAnimal] destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & source) {
	if (this != &source) {
		std::cout << BLUE "[WrongAnimal] assignment operator is called" RESET "\n";
		this->_type = source.getType();
	}
	return (*this);
}

/******************************GETTERS*****************************************/

std::string	WrongAnimal::getType ( void ) const {
	return (this->_type);
}

/******************************PUBLIC******************************************/

void	WrongAnimal::makeSound(void) const {
	std::cout << YELLOW "[WrongAnimal] is making an unknow sound!!!" RESET "\n";
	return ;
}
