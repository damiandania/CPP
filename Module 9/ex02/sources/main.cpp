/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/29 23:06:29 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int	checkArgument(char * str) {
	long int nb = atol(str);
	if (nb > 2147483647 || nb < 0)
		throw std::out_of_range("Value out of range [0 - 2147483647]");

	for (int i = 0; str[i]; i++) {
		if (!isdigit(str[i]))
			throw std::invalid_argument("Only number are allowed");
	}
	return (static_cast<int>(nb));
}

int main(int ac, char **av) {
	try {
		if (ac < 3)
			throw std::invalid_argument ("2 argument min required");

		std::vector<int>	vec;
		std::list<int>		lst;

		for (int i = 1; i <  ac; i++) {
			int nb = checkArgument(av[i]);
			vec.push_back(nb);
			lst.push_back(nb);
		}
		PmergeMe calculate(vec, lst);
	}
	catch (std::exception & e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	};
	return 0;
}
