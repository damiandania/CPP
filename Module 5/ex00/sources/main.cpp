/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/03 15:09:53 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main () {
	std::cout << "----------------------------------------------------------\n";
	// TEST 1
	{
		std::cout << YELLOW "TEST 1:\n" RESET
			"DEFAULT CONSTRUCTOR / LOW GRADE EXCEPTION\n\n";
		try {
			Bureaucrat test1;
			std::cout << test1;
			test1.decrementGrade();
			std::cout << test1;
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 2
	{
		std::cout << YELLOW "TEST 2:\n" RESET
			"ATRIBUTE CONSTRUCTOR / HIGHT GRADE EXCEPTION\n\n";
		try {
			Bureaucrat test2("Test2", 1);
			std::cout << test2;
			test2.incrementGrade();
			std::cout << test2;
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 3
	{
		std::cout << YELLOW "TEST 3:\n" RESET
			"MORE THAN HIGHEST GRADE\n\n";
		try {
			Bureaucrat test3("Test3", 155);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 4
	{
		std::cout << YELLOW "TEST 4:\n" RESET
			"LESS THAN LOWEST GRADE\n\n";
		try {
			Bureaucrat test4("Test4", 0);
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 5
	{
		std::cout << YELLOW "TEST 5:\n" RESET
			"INCREMENT GRADE / DECREMENT GRADE\n\n";
		try {
			Bureaucrat test5("Test5", 130);
			std::cout << test5;
			test5.incrementGrade();
			test5.decrementGrade();
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 6
	{
		std::cout << YELLOW "TEST 6:\n" RESET
			"COPY CONSTRUCTOR / ASSIGNMENT OPERATOR\n\n";
		try {
			Bureaucrat test5("Test5", 60);
			std::cout << test5;
			Bureaucrat test6(test5);
			std::cout << test6;
			Bureaucrat test7;
			std::cout << test7;
			test7 = test5;
			std::cout << test7;
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";
	return (0);
}
