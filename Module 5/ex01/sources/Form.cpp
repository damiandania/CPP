/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:11:45 by damian            #+#    #+#             */
/*   Updated: 2024/04/03 16:21:48 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

/******************************CONSTRUCTORS************************************/

Form::Form(void) :
		_name("Default"),
		_signed(false),
		_signGrade(MIN_GRADE),
		_executeGrade(MIN_GRADE) {
	std::cout << GREEN "[Form] constructor default is called" RESET "\n";
	return ;
}

Form::Form(std::string const & name, const int signGrade, const int executeGrade) :
		_name(name),
		_signed(false),
		_signGrade(signGrade),
		_executeGrade(executeGrade) {
	std::cout << GREEN "[Form] constructor is called" RESET "\n";

	if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw (Form::GradeTooHighException());
	if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw (Form::GradeTooLowException());
	return ;
}

Form::Form(Form const & source) :
		_name(source._name),
		_signed(false),
		_signGrade(source._signGrade),
		_executeGrade(source._executeGrade) {
	std::cout << GREEN "[Form] copy is called" RESET "\n";
	return ;
}

Form::~Form(void) {
	std::cout << BLUE "[Form] " << this->_name
		<< " destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

Form & Form::operator=(Form const & source) {
	std::cout << GREEN "[Form] assignment operator is called" RESET "\n";

	if (this != &source) {
		this->_signed = source._signed;
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & os, Form const & source) {
	os << "[Form] " <<source.getName() << ", is " << (source.getSigned() ?
		"SIGNED" : "NOT SIGNED") << ", Sign grade: " << source.getSignGrade()
		<< ", Execute grade: " << source.getExecuteGrade();
	return (os);
}

/******************************GETTERS*****************************************/

std::string const Form::getName ( void ) const {
	return (this->_name);
}

bool Form::getSigned ( void ) const {
	return (this->_signed);
}

int Form::getSignGrade(void) const {
	return (this->_signGrade);
}

int Form::getExecuteGrade(void) const {
	return (this->_executeGrade);
}

/******************************PUBLIC******************************************/

void Form::beSigned(Bureaucrat & bureaucrat) {
	if (this->_signed)
		throw (Form::SignedException());
	else if (bureaucrat.Bureaucrat::getGrade() > this->_signGrade)
		throw (Form::GradeTooLowException());
	this->_signed = true;
	return ;
}
