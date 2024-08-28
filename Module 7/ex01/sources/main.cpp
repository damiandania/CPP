/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/16 14:24:12 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Iter.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main() {
	//TEST 1
	std::cout << "----------------------------------------------------------\n";
	{
		std::cout << YELLOW "TEST 1: Int\n" RESET;

		int array[10] = {0, 1, 2, 3, 4, 42, 42, 42, 45, 42};

		iter(array, 10, printElement<int>);
	}

	//TEST 2
	std::cout << "----------------------------------------------------------\n";
	{
		std::cout << YELLOW "TEST 2: String\n" RESET;

		std::string array[5] = {"Cat", "Sun", "Mountain", "Airplane", "Happiness"};

		iter(array, 5, printElement<std::string>);
	}

	//TEST 3
	std::cout << "----------------------------------------------------------\n";
	{
		std::cout << YELLOW "TEST 3: Empty\n" RESET;

		int array[0];

		iter(array, 0, printElement<int>);
	}
	std::cout << "----------------------------------------------------------\n";
	return 0;
}
