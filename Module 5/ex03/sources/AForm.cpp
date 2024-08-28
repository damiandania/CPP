/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:11:45 by damian            #+#    #+#             */
/*   Updated: 2024/03/31 18:17:51 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

/******************************CONSTRUCTORS************************************/

AForm::AForm(void) :
		_name("Default"),
		_signed(false),
		_signGrade(MIN_GRADE),
		_executeGrade(MIN_GRADE) {
	std::cout << GREEN "[Form] constructor default is called" RESET "\n";
	return ;
}

AForm::AForm(std::string const & name, const int signGrade, const int executeGrade) :
		_name(name),
		_signed(false),
		_signGrade(signGrade),
		_executeGrade(executeGrade) {
	std::cout << GREEN "[Form] constructor is called" RESET "\n";

	if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw (AForm::GradeTooHighException());
	if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw (AForm::GradeTooLowException());
	return ;
}

AForm::AForm(AForm const & source) :
		_name(source._name),
		_signed(false),
		_signGrade(source._signGrade),
		_executeGrade(source._executeGrade) {
	std::cout << GREEN "[Form] copy is called" RESET "\n";
	return ;
}

AForm::~AForm(void) {
	std::cout << BLUE "[Form] destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

AForm & AForm::operator=(AForm const & source) {
	std::cout << GREEN "[Form] assignment operator is called" RESET "\n";

	if (this != &source) {
		this->_signed = source._signed;
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & os, AForm const & source) {
	os << "[Form] " << source.getName() << ", is " << (source.getSigned() ?
		"SIGNED" : "NOT SIGNED") << ", Sign grade: " << source.getSignGrade()
		<< ", Execute grade: " << source.getExecuteGrade();
	return (os);
}

/******************************GETTERS*****************************************/

std::string const AForm::getName ( void ) const {
	return (this->_name);
}

bool AForm::getSigned ( void ) const {
	return (this->_signed);
}

int AForm::getSignGrade(void) const {
	return (this->_signGrade);
}

int AForm::getExecuteGrade(void) const {
	return (this->_executeGrade);
}

/******************************PUBLIC******************************************/

void AForm::beSigned(Bureaucrat const & bureaucrat) {
	if (this->_signed)
		throw (AForm::SignedException());
	else if (bureaucrat.Bureaucrat::getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
	return ;
}

void AForm::checkRequeriments(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw (AForm::NotSignedException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException());
	this->execute();
	return ;
}

