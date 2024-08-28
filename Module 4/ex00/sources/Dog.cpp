/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:45:51 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/20 18:46:53 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/******************************CONSTRUCTORS************************************/

Dog::Dog(void) : Animal("Dog") {
	std::cout << BLUE "[Dog] constructor is called" RESET "\n";
	return ;
}

Dog::Dog(Dog const & source) : Animal(source) {
	std::cout << BLUE "[Dog] copy is called" RESET "\n";
	*this = source;
	return ;
}

Dog::~Dog(void) {
	std::cout << BLUE "[Dog] destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

Dog &	Dog::operator=(Dog const & source) {
	if (this != &source) {
		std::cout << BLUE "[Dog] assignment operator is called" RESET "\n";
		this->_type = source.getType();
	}
	return (*this);
}

/******************************PUBLIC******************************************/

void	Dog::makeSound(void) const {
	std::cout << YELLOW "[Dog] is barking!!!" RESET "\n";
	return ;
}
