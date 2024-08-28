/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/03 16:22:50 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Form;

class Bureaucrat {
	private:
		std::string const	_name;
		int					_grade;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("[Exception] Highest grade is 1");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("[Exception] Lowest grade is 150");
				}
		};

	public:
		Bureaucrat(void);
		Bureaucrat(std::string const & name, unsigned int grade);
		Bureaucrat(Bureaucrat const & source);
		~Bureaucrat(void);

		Bureaucrat &	operator=(Bureaucrat const & source);

		std::string const	getName(void) const;
		int		getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form & form);
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & source);

#endif
