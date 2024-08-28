/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:39:19 by damiandania       #+#    #+#             */
/*   Updated: 2024/04/03 15:09:22 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/******************************CONSTRUCTORS************************************/

Bureaucrat::Bureaucrat(void) :
		_name("Default"),
		_grade(150) {
	std::cout << GREEN "[Bureaucrat] constructor default is called" RESET "\n";
	return ;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) :
		_name(name),
		_grade(grade) {
	std::cout << GREEN "[Bureaucrat] constructor is called" RESET "\n";
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & source) :
		_name(source._name), _grade(source._grade) {
	std::cout << GREEN "[Bureaucrat] copy is called" RESET "\n";
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << BLUE "[Bureaucrat] " << this->_name << " destructor is called"
		RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & source) {
	if (this != &source) {
		this->_grade = source._grade;
	}
	std::cout << GREEN "[Bureaucrat] assignment operator is called" RESET "\n";
	return (*this);
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & source) {
	os << source.getName() << ", bureaucrat grade " << source.getGrade() << "\n";
	return (os);
}

/******************************GETTERS*****************************************/

std::string const Bureaucrat::getName ( void ) const {
	return (this->_name);
}

int Bureaucrat::getGrade ( void ) const {
	return (this->_grade);
}

/******************************PUBLIC******************************************/

void Bureaucrat::incrementGrade ( void ) {
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
	std::cout << "[Bureaucrat] " << this->_name << " has increment the grade to "
		<< this->_grade << "\n";
	return ;
}

void Bureaucrat::decrementGrade(void) {
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
	std::cout << "[Bureaucrat] " << this->_name << " has decrement the grade to "
		<< this->_grade << "\n";
	return ;
}
