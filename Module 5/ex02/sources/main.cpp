/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/03 17:14:10 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <cstdlib>


template<typename T>

void runTest(const std::string& target) {
	srand(time(NULL));
	std::cout << "----------------------------------------------------------\n";

	// TEST 1
	{
		std::cout << YELLOW "TEST 1:\n" RESET
			"DEFAULT CONSTRUCTOR / SIGN FORM / EXECUTE FORM / GETTERS\n\n";

		try {
			T			form1;
			Bureaucrat	bureaucrat1("B1", (form1.getExecuteGrade()));

			std::cout << form1 << "\n";
			std::cout << bureaucrat1 << "\n";
			bureaucrat1.signForm(form1);
			std::cout << form1 << "\n";
			bureaucrat1.executeForm(form1);
			std::cout << "Target: " << form1.getTarget() << "\n";
			std::cout << "Signed: " << (form1.getSigned() ? "Yes" : "NO") << "\n";
			std::cout << "Sign Grade: " << form1.getSignGrade() << "\n";
			std::cout << "Execute Grade: " << form1.getExecuteGrade() << "\n";
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 2
	{
		std::cout << YELLOW "TEST 2:\n" RESET
			"ATRIBUTE CONSTRUCTOR / EXECUTE FORM LOW GRADE EXCEPTION\n\n";

		try {
			T			form2(target + "2");
			Bureaucrat	bureaucrat2("B2", (form2.getExecuteGrade() + 1));

			std::cout << form2 << "\n";
			std::cout << bureaucrat2 << "\n";
			bureaucrat2.signForm(form2);
			std::cout << form2 << "\n";
			bureaucrat2.executeForm(form2);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 3
	{
		std::cout << YELLOW "TEST 3:\n" RESET
			"ATRIBUTE CONSTRUCTOR / SIGN FORM LOW GRADE EXCEPTION\n\n";

		try {
			T			form3(target + "3");
			Bureaucrat	bureaucrat3("B3", (form3.getSignGrade() + 1));

			std::cout << form3 << "\n";
			std::cout << bureaucrat3 << "\n";
			bureaucrat3.signForm(form3);
			std::cout << form3 << "\n";
			bureaucrat3.executeForm(form3);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 4
	{
		std::cout << YELLOW "TEST 4:\n" RESET
			"ALREADY SIGNED / NOT SIGNED\n\n";

		try {
			T			form4(target + "4");
			Bureaucrat	bureaucrat4("B4",(form4.getExecuteGrade()));

			std::cout << form4 << "\n";
			std::cout << bureaucrat4 << "\n";
			bureaucrat4.executeForm(form4);
			bureaucrat4.signForm(form4);
			std::cout << form4 << "\n";
			bureaucrat4.signForm(form4);
			std::cout << form4 << "\n";
			bureaucrat4.executeForm(form4);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";


	// TEST 5
	{
		std::cout << YELLOW "TEST 5:\n" RESET
			"COPY CONSTRUCTOR / ASSIGNMENT OPERATOR\n\n";

		try {
			T			form5(target + "5");
			Bureaucrat	bureaucrat5("B5",1);
			bureaucrat5.signForm(form5);
			std::cout << form5 << "\n\n";

			T form6(form5);
			std::cout << form6 << "\n\n";

			T			form7(target + "7");
			std::cout << form7 << "\n";
			form7 = form5;
			std::cout << form7 << "\n\n";

			bureaucrat5.signForm(form7);
			bureaucrat5.executeForm(form7);
			bureaucrat5.executeForm(form7);
			bureaucrat5.executeForm(form7);
			bureaucrat5.executeForm(form7);
			bureaucrat5.executeForm(form7);
			bureaucrat5.executeForm(form7);
			bureaucrat5.executeForm(form7);
			bureaucrat5.executeForm(form7);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";
}

int main() {
	std::string target = "TARGET";

	// std::cout << YELLOW "TESTING: ShrubberyCreationForm:\n" RESET;
	// runTest<ShrubberyCreationForm>(target);

	std::cout << YELLOW "TESTING: RobotomyRequestForm:\n" RESET;
	runTest<RobotomyRequestForm>(target);

	// std::cout << YELLOW "TESTING: PresidentialPardonForm:\n" RESET;
	// runTest<PresidentialPardonForm>(target);

	return 0;
}
