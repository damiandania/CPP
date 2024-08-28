/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:07:11 by ddania-c          #+#    #+#             */
/*   Updated: 2024/02/23 13:46:50 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else{
		for (int i = 1; av[i]; i++) {
			std::string str = (av[i]);
			for(std::string::iterator it = str.begin(); it != str.end(); it++)
				*it = std::toupper(*it);
			std::cout << str;
		}
	}
	std::cout << '\n';
	return (0);
}
