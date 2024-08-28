/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat .cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:45:51 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/16 23:12:07 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/******************************CONSTRUCTORS************************************/

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << BLUE "[WrongCat] constructor is called" RESET "\n";
	return ;
}

WrongCat::WrongCat(WrongCat const & source) : WrongAnimal(source) {
	std::cout << BLUE "[WrongCat] copy is called" RESET "\n";
	*this = source;
	return ;
}

WrongCat::~WrongCat(void) {
	std::cout << BLUE "[WrongCat] destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

WrongCat &	WrongCat::operator=(WrongCat const & source) {
	if (this != &source) {
		std::cout << BLUE "[WrongCat] assignment operator is called" RESET "\n";
		this->_type = source.getType();
	}
	return (*this);
}

/******************************PUBLIC******************************************/

void	WrongCat::makeSound(void) const {
	std::cout << YELLOW "[WrongCat] is meaowing!!!" RESET "\n";
	return ;
}
