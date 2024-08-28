/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:11:45 by damian            #+#    #+#             */
/*   Updated: 2024/03/29 23:04:07 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/******************************CONSTRUCTORS************************************/

PresidentialPardonForm::PresidentialPardonForm(void) :
		AForm("PresidentialPardonForm", 25, 5),
		_target("Default") {
	std::cout << GREEN "[PresidentialPardonForm] constructor default is called\n" RESET;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
		AForm("PresidentialPardonForm", 25, 5),
		_target(target) {
	std::cout << GREEN "[PresidentialPardonForm] constructor is called\n" RESET;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & source) :
		AForm(source),
		_target(source._target) {
	std::cout << GREEN "[PresidentialPardonForm] copy is called\n" RESET;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << BLUE "[PresidentialPardonForm] destructor is called\n" RESET;
	return ;
}

/******************************OPERATORS***************************************/

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & source) {
	std::cout << GREEN "[PresidentialPardonForm] assignment operator is called\n" RESET;

	if (this != &source) {
		this->_target = source._target;
	}
	return (*this);
}

/******************************GETTERS*****************************************/

std::string const PresidentialPardonForm::getTarget ( void ) const {
	return (this->_target);
}

/******************************PUBLIC******************************************/

void PresidentialPardonForm::execute( void ) const {
	std::cout << MAGENTA << this->_target
		<< " has been pardoned by Zaphod Beeblebrox.\n" RESET;
	return ;
}
