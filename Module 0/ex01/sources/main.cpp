/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:16 by ddania-c          #+#    #+#             */
/*   Updated: 2024/02/21 14:15:09 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

void	showPhone() {
	system("clear");
	std::cout	<< 	"   _"				<< std::endl
				<<	"  | |"				<< std::endl
				<<	" _| |___________ "	<< std::endl
				<<	"|          U    |"	<< std::endl
				<<	"| ====o======== |"	<< std::endl
				<<	"| ___________42.|"	<< std::endl
				<<	"||   Welcome   ||"	<< std::endl
				<<	"||             ||"	<< std::endl
				<<	"||             ||"	<< std::endl
				<<	"||             ||"	<< std::endl
				<<	"||_____________||"	<< std::endl
				<<	"|---------------|"	<< std::endl
				<<	"|[1__][2__][3__]|"	<< std::endl
				<<	"|[4__][5__][6__]|"	<< std::endl
				<<	"|[7__][8__][9__]|"	<< std::endl
				<<	"|[*__][0__][#__]|"	<< std::endl
				<<	"|_______________|"	<< std::endl;
	sleep(2);
	system("clear");
}

int main() {
	PhoneBook	phone;
	std::string	input;

	showPhone();
	while (1) {
		std::cout	<< "\n+-----MENU-----+\n"
					<< " 1.ADD\n"
					<< " 2.SEARCH\n"
					<< " 3.EXIT\n"
					<< "Enter a command: ";
		if (!std::getline(std::cin, input))
			return 1;
		input = phone.trimSpaces(input);

		for (std::string::iterator it = input.begin(); it != input.end(); ++it) {
 			*it = std::toupper(*it);
		}
		if (input == "ADD") {
			if (!phone.addContact())
				break ;
		}
		else if (input == "SEARCH") {
			if (!phone.seachContact())
				break ;
		}
		else if (input == "EXIT"){
			std::cout << "\033[1;32mClosing PhoneBook...\n\033[0m";
			break;
		}
		else
			std::cout	<< "\033[1;31mNot a valid command...\n\033[0m";
	}

	return (0);
}
