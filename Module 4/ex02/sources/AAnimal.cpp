/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:39:19 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/21 14:16:29 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

/******************************CONSTRUCTORS************************************/

AAnimal::AAnimal(void) : _type("Unknow") {
	std::cout << GREEN "[AAnimal] constructor default is called" RESET "\n";
	return ;
}

AAnimal::AAnimal(std::string const & type) : _type(type) {
	std::cout << GREEN "[AAnimal] constructor is called" RESET "\n";
	return ;
}

AAnimal::AAnimal(AAnimal const & source) {
	std::cout << GREEN "[AAnimal] copy is called" RESET "\n";
	*this = source;
	return ;
}

AAnimal::~AAnimal(void) {
	std::cout << RED "[AAnimal] destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

AAnimal &	AAnimal::operator=(AAnimal const & source) {
	if (this != &source) {
		std::cout << GREEN "[AAnimal] assignment operator is called" RESET "\n";
		this->_type = source.getType();
	}
	return (*this);
}

/******************************GETTERS*****************************************/

std::string	AAnimal::getType ( void ) const {
	return (this->_type);
}

/******************************PUBLIC******************************************/

void	AAnimal::makeSound(void) const {
	std::cout << YELLOW "[AAnimal] is making an unknow sound!!!" RESET "\n";
	return ;
}
