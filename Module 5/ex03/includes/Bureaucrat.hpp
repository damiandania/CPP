/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/30 09:46:13 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat {
	private:
		std::string const	_name;
		int		_grade;

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
		void				signForm(AForm & form);
		void 				executeForm(AForm & form) const;

};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & source);

#endif
