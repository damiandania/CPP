/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:39:19 by damiandania       #+#    #+#             */
/*   Updated: 2024/04/03 17:53:14 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

/******************************CONSTRUCTORS************************************/

Intern::Intern(void) {
	std::cout << GREEN "[Intern] constructor default is called\n" RESET;
	return ;
}

Intern::Intern(Intern const & source) {
	std::cout << GREEN "[Intern] copy is called\n" RESET;
	(void)source;
	return ;
}

Intern::~Intern(void) {
	std::cout << BLUE "[Intern] destructor is called\n" RESET;
	return ;
}

/******************************OPERATORS***************************************/

Intern & Intern::operator=(Intern const & source) {
	std::cout << GREEN "[Intern] assignment operator is called\n" RESET;
	(void)source;
	return (*this);
}

/******************************STATIC******************************************/

AForm * Intern::makeShrubberyCreationForm(std::string const & target) {
	return (new ShrubberyCreationForm(target));
}

AForm * Intern::makeRobotomyRequestForm(std::string const & target) {
	return (new RobotomyRequestForm(target));
}

AForm * Intern::makePresidentialPardonForm(std::string const & target) {
	return (new PresidentialPardonForm(target));
}

/******************************PUBLIC******************************************/

AForm * Intern::makeForm(std::string formName, std::string target) {
	AForm *	(Intern::*funtion[3])(std::string const &) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm};

	std::string form[3] =
		{"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++) {
		if (form[i] == formName) {
			std::cout << CYAN "[Intern] creates " << formName << "\n" RESET;
			return ((this->*funtion[i])(target));
		}
	}
	throw Intern::WrongFormNameException();
}
