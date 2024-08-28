/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:45:51 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/21 14:57:12 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/******************************CONSTRUCTORS************************************/

Cat::Cat(void) : AAnimal("Cat"), _brain(new Brain("Cat")) {
	std::cout << GREEN "[Cat] constructor is called with new brain" RESET "\n";
	return ;
}

Cat::Cat(Cat const & source) : AAnimal(source), _brain(NULL) {
	std::cout << GREEN "[Cat] copy is called" RESET "\n";
	*this = source;
	return ;
}

Cat::~Cat(void) {
	std::cout << RED "[Cat] destructor is called"	RESET "\n";
	delete this->_brain;
	return ;
}

/******************************OPERATORS***************************************/

Cat &	Cat::operator=(Cat const & source) {
	if (this != &source) {
		std::cout << GREEN "[Cat] assignment operator is called" RESET "\n";
		this->_type = source._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*source._brain);
	}
	return (*this);
}

/******************************GETTER******************************************/

void	Cat::getIdeas(void) const {
	for (int i = 0; i < 100; i++)
		std::cout << _brain->getIdea(i) << '\n';
	return ;
}

/******************************PUBLIC******************************************/

void	Cat::makeSound(void) const {
	std::cout << YELLOW "[Cat] is meaowing!!!" RESET "\n";
	return ;
}
