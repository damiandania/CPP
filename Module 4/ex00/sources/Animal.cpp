/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:39:19 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/20 18:46:58 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/******************************CONSTRUCTORS************************************/

Animal::Animal(void) : _type("Unknow") {
	std::cout << BLUE "[Animal] constructor default is called" RESET "\n";
	return ;
}

Animal::Animal(std::string const & type) : _type(type) {
	std::cout << BLUE "[Animal] constructor is called" RESET "\n";
	return ;
}

Animal::Animal(Animal const & source) {
	std::cout << BLUE "[Animal] copy is called" RESET "\n";
	*this = source;
	return ;
}

Animal::~Animal(void) {
	std::cout << BLUE "[Animal] destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

Animal &	Animal::operator=(Animal const & source) {
	if (this != &source) {
		std::cout << BLUE "[Animal] assignment operator is called" RESET "\n";
		this->_type = source.getType();
	}
	return (*this);
}

/******************************GETTERS*****************************************/

std::string	Animal::getType ( void ) const {
	return (this->_type);
}

/******************************PUBLIC******************************************/

void	Animal::makeSound(void) const {
	std::cout << YELLOW "[Animal] is making an unknow sound!!!" RESET "\n";
	return ;
}
