/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/24 13:24:57 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"


int main() {
	MutantStack<int> mutantStack;

	// TEST 1
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 1: Pushing elements\n" RESET;

	mutantStack.push(1);
	mutantStack.push(2);
	mutantStack.push(3);
	mutantStack.push(4);
	mutantStack.push(5);

	std::cout << "MutantStack size: " << mutantStack.size() << std::endl;

	// TEST 2
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 2: Iterating\n" RESET;
	for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// TEST 3
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 3: Reverser iterating\n" RESET;
	for (MutantStack<int>::reverse_iterator it = mutantStack.rbegin(); it != mutantStack.rend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// TEST 4
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 4: First and last element\n" RESET;
	std::cout << "First: " << mutantStack.top() << std::endl;
	std::cout << "Last: " << *mutantStack.begin() << std::endl;

	// TEST 5
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 5: Removing last element\n" RESET;
	mutantStack.pop();

	std::cout << "MutantStack size: " << mutantStack.size() << std::endl;
	for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// TEST 6
	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST 6: Assignment operator\n" RESET;
	MutantStack<int> mutantStack2;

	mutantStack2 = mutantStack;
	std::cout << "MutantStack copy: " << std::endl;
	for (MutantStack<int>::iterator it = mutantStack2.begin(); it != mutantStack2.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------\n";
	return 0;
}

