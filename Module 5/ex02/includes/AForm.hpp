/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/03 16:41:48 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;

	protected:

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

		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("[Exception] The form is not signed yet");
				}
		};

	public:
		AForm(void);
		AForm(std::string const & name, const int signGrade, const int executeGrade);
		AForm(AForm const & source);
		virtual ~AForm(void);

		AForm &	operator=(AForm const & source);

		std::string const	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void			beSigned(Bureaucrat const & bureaucrat) ;
		void			checkRequeriments(Bureaucrat const & executor) const;
		virtual void	execute( void ) const = 0;
};

std::ostream & operator<<(std::ostream & os, AForm const & source);

#endif
