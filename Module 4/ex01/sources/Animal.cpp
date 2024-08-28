/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:39:19 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/21 14:16:29 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/******************************CONSTRUCTORS************************************/

Animal::Animal(void) : _type("Unknow") {
	std::cout << GREEN "[Animal] constructor default is called" RESET "\n";
	return ;
}

Animal::Animal(std::string const & type) : _type(type) {
	std::cout << GREEN "[Animal] constructor is called" RESET "\n";
	return ;
}

Animal::Animal(Animal const & source) {
	std::cout << GREEN "[Animal] copy is called" RESET "\n";
	*this = source;
	return ;
}

Animal::~Animal(void) {
	std::cout << RED "[Animal] destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

Animal &	Animal::operator=(Animal const & source) {
	if (this != &source) {
		std::cout << GREEN "[Animal] assignment operator is called" RESET "\n";
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
