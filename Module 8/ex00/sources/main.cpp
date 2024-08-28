/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/23 11:16:25 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#include <vector>
#include <list>
#include <deque>

template <typename T>
void runTest(T const & container, int toFind) {
		try {
			typename T::const_iterator it = easyfind(container, toFind);
			std::cout << "Element found: " << *it << std::endl;
		} catch (const std::exception & e) {
			std::cerr << RED "Element not found" RESET << std::endl;
		}
}

int main() {
	std::cout << "----------------------------------------------------------\n";
	{
		std::cout << YELLOW "TEST 1: Vector<int>\n" RESET;
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		runTest(vec, 3);
	}
	std::cout << "----------------------------------------------------------\n";
	{
		std::cout << YELLOW "TEST 1: Vector<int> exception\n" RESET;
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		runTest(vec, 6);
	}
	std::cout << "----------------------------------------------------------\n";
	{
		std::cout << YELLOW "TEST 3: List<int>\n" RESET;
		std::list<int> lst;
		lst.push_back(6);
		lst.push_back(7);
		lst.push_back(8);
		lst.push_back(9);
		lst.push_back(10);
		runTest(lst, 8);
	}
	std::cout << "----------------------------------------------------------\n";
	{
		std::cout << YELLOW "TEST 4: List<int> exception\n" RESET;
		std::list<int> lst;
		lst.push_back(6);
		lst.push_back(7);
		lst.push_back(8);
		lst.push_back(9);
		lst.push_back(10);
		runTest(lst, 2);
	}
	std::cout << "----------------------------------------------------------\n";
	{
		std::cout << YELLOW "TEST 5: Deque<int>\n" RESET;
		std::deque<int> lst;
		lst.push_back(11);
		lst.push_back(12);
		lst.push_back(13);
		lst.push_back(14);
		lst.push_back(15);
		runTest(lst, 14);
	}
	std::cout << "----------------------------------------------------------\n";
	{
		std::cout << YELLOW "TEST 6: Deque<int> exception\n" RESET;
		std::deque<int> lst;
		lst.push_back(11);
		lst.push_back(12);
		lst.push_back(13);
		lst.push_front(14);
		lst.push_back(15);
		runTest(lst, 2);
	}
	std::cout << "----------------------------------------------------------\n";
	return 0;
}
