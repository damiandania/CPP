/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:11:45 by damian            #+#    #+#             */
/*   Updated: 2024/03/29 22:53:50 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

/******************************CONSTRUCTORS************************************/

ShrubberyCreationForm::ShrubberyCreationForm(void) :
		AForm("ShrubberyCreationForm", 145, 137),
		_target("Default") {
	std::cout << GREEN "[ShrubberyCreationForm] constructor default is called\n" RESET;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
		AForm("ShrubberyCreationForm", 145, 137),
		_target(target) {
	std::cout << GREEN "[ShrubberyCreationForm] constructor is called\n" RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & source) :
		AForm(source),
		_target(source._target) {
	std::cout << GREEN "[ShrubberyCreationForm] copy is called\n" RESET;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << BLUE "[ShrubberyCreationForm] destructor is called\n" RESET;
	return ;
}

/******************************OPERATORS***************************************/

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & source) {
	std::cout << GREEN "[ShrubberyCreationForm] assignment operator is called\n" RESET;

	if (this != &source) {
		this->_target = source._target;
	}
	return (*this);
}

/******************************GETTERS*****************************************/

std::string const ShrubberyCreationForm::getTarget ( void ) const {
	return (this->_target);
}

/******************************PUBLIC******************************************/

void ShrubberyCreationForm::execute( void ) const {
	std::ofstream outFile((this->_target + "_shrubbery").c_str());

	if (!outFile.is_open())
		throw std::runtime_error("Error: openning the file");

	outFile <<	"			# #### ####\n"
				"		### ||#|### |/####\n"
				"		##||#/ |||/##/_/##/_#\n"
				"		###  ||###|/ || # ###\n"
				"	##_|_#|_|## | #/###_/_####\n"
				"	## #### # | #| /  #### ##/##\n"
				"	__#_--###`  |{,###---###-~\n"
				"				| }{\n"
				"				}}{\n"
				"				}}{\n"
				"			ejm  {{}\n"
				"		, -=-~{ .-^- _\n"
				"				`}\n";
	outFile.close();
	std::cout << MAGENTA "The file " << this->_target
		<< "_shrubbery has been created\n" RESET;
	std::cout << MAGENTA "Has been planted shrubbery at " << this->_target
		<< "\n" RESET;
	return ;
}
