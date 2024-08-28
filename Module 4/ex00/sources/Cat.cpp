/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:45:51 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/20 18:46:49 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/******************************CONSTRUCTORS************************************/

Cat::Cat(void) : Animal("Cat") {
	std::cout << BLUE "[Cat] constructor is called" RESET "\n";
	return ;
}

Cat::Cat(Cat const & source) : Animal(source) {
	std::cout << BLUE "[Cat] copy is called" RESET "\n";
	*this = source;
	return ;
}

Cat::~Cat(void) {
	std::cout << BLUE "[Cat] destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

Cat &	Cat::operator=(Cat const & source) {
	if (this != &source) {
		std::cout << BLUE "[Cat] assignment operator is called" RESET "\n";
		this->_type = source.getType();
	}
	return (*this);
}

/******************************PUBLIC******************************************/

void	Cat::makeSound(void) const {
	std::cout << YELLOW "[Cat] is meaowing!!!" RESET "\n";
	return ;
}
