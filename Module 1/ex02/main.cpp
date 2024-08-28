/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:04:21 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/18 14:42:46 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string		original = "HI THIS IS BRAIN";
	std::string*	stringPTR = &original;
	std::string&	stringREF = original;

	std::cout << "original	memory address:\t" << &original << std::endl;
	std::cout << "stringPTR	memory address:\t" << stringPTR << std::endl;
	std::cout << "stringREF	memory address:\t" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "original value:\t\t\t" << original << std::endl;
	std::cout << "stringPTR value:\t\t" << *stringPTR << std::endl;
	std::cout << "stringREF value:\t\t" << stringREF << std::endl;

	return (0);
}
