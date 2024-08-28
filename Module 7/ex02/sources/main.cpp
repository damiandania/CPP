/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/16 14:26:23 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <Array.hpp>
#include <cstdlib>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define MAX_VAL 750

int main() {
	// TEST SUBJECT

	std::cout << "----------------------------------------------------------\n";
	std::cout << YELLOW "TEST SUBJECT\n" RESET;

	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 1
	{
		std::cout << YELLOW "TEST 1: Int array\n" RESET;

		Array<int> empty;

		Array<int> array(5);
		array[0] = 0;
		array[1] = 1;
		array[2] = 2;
		array[3] = 3;
		array[4] = 4;

		std::cout << array << std::endl;
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 2
	{
		std::cout << YELLOW "TEST 2: String array\n" RESET;

		Array<std::string> array(5);
		array[0] = "Cat";
		array[1] = "Sun";
		array[2] = "Mountain";
		array[3] = "Airplane";
		array[4] = "Happiness";

		std::cout << array << std::endl;
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 3
	{
		std::cout << YELLOW "TEST 3: Index out of limits\n" RESET;

		try {
			Array<int> array(5);
			std::cout << array[5];
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
		try {
			Array<int> array(5);
			std::cout << array[-2];
		}
		catch (std::exception & e) {
			std::cerr << RED << e.what() << std::endl << RESET;
		}
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 4
	{
		std::cout << YELLOW "TEST 4: Operator []\n" RESET;

		Array<std::string> array(5);
		array[0] = "Cat";
		array[1] = "Sun";
		array[2] = "Mountain";
		array[3] = "Airplane";
		array[4] = "Happiness";

		std::cout << "Array[3] = " << array[3] << std::endl;
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 5
	{
		std::cout << YELLOW "TEST 5: Copy constructor\n" RESET;

		Array<float> array(3);
		array[0] = 0.5f;
		array[1] = 1.5f;
		array[2] = 2.5f;
		std::cout << array << std::endl;

		Array<float> copy(array);
		std::cout << copy << std::endl;
	}
	std::cout << "----------------------------------------------------------\n";

	// TEST 6
	{
		std::cout << YELLOW "TEST 6: Operator =\n" RESET;

		Array<double> array(3);
		array[0] = 0.5;
		array[1] = 1.5;
		array[2] = 2.5;
		std::cout << array << std::endl;

		Array<double> copy(5);
		copy[0] = -0.5;
		copy[1] = -1.5;
		copy[2] = -2.5;
		copy[3] = -3.5;
		copy[4] = -4.5;
		copy = array;
		std::cout << copy << std::endl;

	}
	std::cout << "----------------------------------------------------------\n";

	return (0);
}
