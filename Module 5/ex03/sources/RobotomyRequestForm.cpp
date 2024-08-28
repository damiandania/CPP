/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:11:45 by damian            #+#    #+#             */
/*   Updated: 2024/03/30 00:04:10 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>

/******************************CONSTRUCTORS************************************/

RobotomyRequestForm::RobotomyRequestForm(void) :
		AForm("RobotomyRequestForm", 72, 45),
		_target("Default") {
	std::cout << GREEN "[RobotomyRequestForm] constructor default is called\n" RESET;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
		AForm("RobotomyRequestForm", 72, 45),
		_target(target) {
	std::cout << GREEN "[RobotomyRequestForm] constructor is called\n" RESET;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & source) :
		AForm(source),
		_target(source._target) {
	std::cout << GREEN "[RobotomyRequestForm] copy is called\n" RESET;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << BLUE "[RobotomyRequestForm] destructor is called\n" RESET;
	return ;
}

/******************************OPERATORS***************************************/

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & source) {
	std::cout << GREEN "[RobotomyRequestForm] assignment operator is called\n" RESET;

	if (this != &source) {
		this->_target = source._target;
	}
	return (*this);
}

/******************************GETTERS*****************************************/

std::string const RobotomyRequestForm::getTarget ( void ) const {
	return (this->_target);
}

/******************************PUBLIC******************************************/

void RobotomyRequestForm::execute( void ) const {

	std::cout << MAGENTA "ZzZzZzZz... Clank! Clank! Clank! ZzZzZzZz...\n" << RESET;
	if (rand() % 2)
		std::cout << MAGENTA << this->_target << " has been robotomized.\n" RESET;
	else
		std::cout << MAGENTA << this->_target << " has been failed to be robotomized.\n" RESET;
	return ;
}
