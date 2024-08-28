/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:42:16 by damian            #+#    #+#             */
/*   Updated: 2024/04/03 17:50:43 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		class WrongFormNameException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("[Exception] Wrong name form");
				}
		};
		AForm *	makeShrubberyCreationForm(std::string const & target);
		AForm *	makeRobotomyRequestForm(std::string const & target);
		AForm *	makePresidentialPardonForm(std::string const & target);

	public:
		Intern(void);
		Intern(Intern const & source);
		virtual ~Intern(void);

		Intern &	operator=(Intern const & source);

		AForm * makeForm(std::string formName, std::string target);
};

#endif
