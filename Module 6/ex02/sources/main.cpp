/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/15 16:03:35 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <iostream>
#include <cstdlib>

Base * generate(void) {
	int random = std::rand() % 3;
	switch (random) {
		case 0:
			std::cout << YELLOW "[Generate] Type A " RESET;
			return new A;
		case 1:
			std::cout << YELLOW "[Generate] Type B " RESET;
			return new B;
		case 2:
			std::cout << YELLOW "[Generate] Type C " RESET;
			return new C;
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << BLUE "[Identify*] Type A " RESET;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << BLUE "[Identify*] Type B " RESET;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << BLUE "[Identify*] Type C " RESET;
	else
		std::cout << BLUE "[Identify*] Type unknow" RESET;
}

void identify(Base& p)  {
	try {
		dynamic_cast<A&>(p);
		(void)p;
		std::cout << RED "[Identify&] Type A " RESET;
	}
	catch (std::exception & e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << RED "[Identify&] Type B " RESET;
	}
	catch (std::exception & e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << RED "[Identify&] Type C " RESET;
	}
	catch (std::exception & e) {}
}

int main() {
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		Base * base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl << std::endl;
	}

	return (0);
}
