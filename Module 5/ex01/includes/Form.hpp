/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/03 16:36:41 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_signed;

		const int			_signGrade;
		const int			_executeGrade;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("[Exception] Grade is too high");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("[Exception] Grade is too low");
				}
		};

		class SignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("[Exception] The form is already signed");
				}
		};

	public:
		Form(void);
		Form(std::string const & name, const int signGrade, const int executeGrade);
		Form(Form const & source);
		~Form(void);

		Form &	operator=(Form const & source);

		std::string const	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void				beSigned(Bureaucrat & bureaucrat);
};

std::ostream & operator<<(std::ostream & os, Form const & source);

#endif
