/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/03 17:24:38 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

void runTest(std::string formName, std::string target, int * i) {
	{
		std::cout << YELLOW "TEST " << *i << "\n" RESET;

		(*i)++;
		try {
			Intern	intern;
			AForm	*rrf;

			rrf = intern.makeForm(formName, target);
			Bureaucrat	bureaucrat("Bureau", rrf->getExecuteGrade());

			std::cout << *rrf << '\n';
			std::cout << bureaucrat << '\n';
			bureaucrat.signForm(*rrf);
			bureaucrat.executeForm(*rrf);

			delete rrf;
		}
		catch (std::exception const & e) {
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";
}

int main() {
	int i = 1;

	runTest("shrubbery creation", "Target1", &i);
	runTest("robotomy request", "Target2", &i);
	runTest("presidential pardon", "Target3", &i);
	runTest("shrubbery form", "Target4", &i);
	runTest("", "", &i);

	return 0;
}
