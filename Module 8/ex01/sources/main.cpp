/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/24 13:20:46 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main() {
	//TEST 1
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 1: Test Subject\n" RESET;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	//TEST 2
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 2: Add funtion\n" RESET;

	Span sp2 = Span(10);
	sp2.addNumber(5);
	sp2.addNumber(35);
	sp2.addNumber(17);
	sp2.addNumber(45);
	sp2.addNumber(243);
	std::cout << "Vector: " << sp2 << std::endl;

	//TEST 3
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 3: Shortest and Longest\n" RESET;

	std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp2.longestSpan() << std::endl;

	//TEST 4
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 4: AddRange\n" RESET;

	std::vector<int> toAdd;
	toAdd.push_back(2);
	toAdd.push_back(46);
	toAdd.push_back(75);
	toAdd.push_back(88);
	toAdd.push_back(9);

	try {
		sp2.addRange(toAdd.begin(), toAdd.end());
		std::cout << "Vector: " << sp2 << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << RED << e.what() << RESET;
	};

	std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp2.longestSpan() << std::endl;

	//TEST 5
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 5: Copy and Max size\n" RESET;

	Span copy(sp2);
	std::cout << "Copy: " << copy << std::endl;
	try {
		copy.addRange(toAdd.begin(), toAdd.end());
		std::cout << copy << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	};
	try {
		copy.addNumber(5);
		std::cout << copy << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	};

	std::cout << "----------------------------------------------------------\n";
	return 0;
}
