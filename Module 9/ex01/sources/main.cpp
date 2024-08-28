/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/05/01 13:44:37 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main(int ac, char **av) {
	try {
		if (ac != 2)
			throw std::runtime_error ("This program works with 1 argument");

		std::string	input(av[1]);
		RPN 		rpn(input);

		std::cout << rpn.getResult() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	};
	return 0;
}
