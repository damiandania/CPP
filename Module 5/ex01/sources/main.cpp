/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/03 16:39:38 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main () {
	std::cout << "----------------------------------------------------------\n";
	// TEST 1
	{
		try {
			std::cout << YELLOW "TEST 1:\n" RESET
				"DEFAULT CONSTRUCTOR / SIGN FORM\n\n";

			Form		form1;
			Bureaucrat	bureaucrat1("B1", 150);

			std::cout << form1 << "\n";
			std::cout << bureaucrat1 << "\n";
			bureaucrat1.signForm(form1);
			std::cout << form1 << "\n";
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 2
	{
		try {
			std::cout << YELLOW "TEST 2:\n" RESET
				"ATRIBUTE CONSTRUCTOR / SIGN FORM LOW GRADE EXCEPTION\n\n";

			Form		form2("F2", 30, 20);
			Bureaucrat	bureaucrat2("B2",40);

			std::cout << form2 << "\n";
			std::cout << bureaucrat2 << "\n";
			bureaucrat2.signForm(form2);
			std::cout << form2 << "\n";
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 3
	{
		std::cout << YELLOW "TEST 3:\n" RESET
			"MORE THAN HIGHEST GRADE\n\n";

		try {
				Form		form3("F3", 0, 60);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET "\n";
		}
		try {
				Form		form3("F3", 60, 0);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET "\n";
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 4
	{
		std::cout << YELLOW "TEST 4:\n" RESET
			"LESS THAN LOWEST GRADE\n\n";

		try {
				Form		form4("F4", 155, 60);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET "\n";
		}
		try {
				Form		form4("F4", 60, 155);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET "\n";
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 5
	{
		try {
			std::cout << YELLOW "TEST 5:\n" RESET
				"ALREADY SIGNED\n\n";

			Form		form5("F5", 20, 10);
			Bureaucrat	bureaucrat5("B5",10);

			std::cout << form5 << "\n";
			std::cout << bureaucrat5 << "\n";
			bureaucrat5.signForm(form5);
			std::cout << form5 << "\n";
			bureaucrat5.signForm(form5);
			std::cout << form5 << "\n";
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 6
	{
		try {
			std::cout << YELLOW "TEST 6:\n" RESET
				"COPY CONSTRUCTOR / ASSIGNMENT OPERATOR\n\n";

			Form		form6("F6", 20, 10);
			Bureaucrat	bureaucrat6("B6",10);
			bureaucrat6.signForm(form6);
			std::cout << form6 << "\n\n";

			Form form7(form6);
			std::cout << form7 << "\n\n";

			Form	form8("F8", 40, 20);
			std::cout << form8 << "\n";
			form8 = form6;
			std::cout << form8 << "\n\n";

			bureaucrat6.signForm(form8);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";
	return (0);
}
