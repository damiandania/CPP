/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:45:51 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/21 15:39:52 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/******************************CONSTRUCTORS************************************/

Dog::Dog(void) : Animal("Dog"), _brain(new Brain("Dog")) {
	std::cout << GREEN "[Dog] constructor is called with new brain" RESET "\n";
	return ;
}

Dog::Dog(Dog const & source) : Animal(source), _brain(NULL) {
	std::cout << GREEN "[Dog] copy is called" RESET "\n";
	*this = source;
	return ;
}

Dog::~Dog(void) {
	std::cout << RED "[Dog] destructor is called"	RESET "\n";
	delete this->_brain;
	return ;
}

/******************************OPERATORS***************************************/

Dog &	Dog::operator=(Dog const & source) {
	if (this != &source) {
		std::cout << GREEN "[Dog] assignment operator is called" RESET "\n";
		this->_type = source._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*source._brain);
	}
	return (*this);
}

/******************************GETTER******************************************/

void	Dog::getIdeas(void) const {
		for (int i = 0; i < 100; i++)
		std::cout << _brain->getIdea(i) << '\n';
	return ;
}

/******************************PUBLIC******************************************/

void	Dog::makeSound(void) const {
	std::cout << YELLOW "[Dog] is barking!!!" RESET "\n";
	return ;
}
