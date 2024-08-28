/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:50:26 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/15 15:52:07 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include "../includes/Serializer.hpp"
#include <iostream>

int main() {
	Data data = {"Test", 10};

	uintptr_t	serializeTest = Serializer::serialize(&data);
	Data*		deserializeTest = Serializer::deserialize(serializeTest);

	if (deserializeTest == &data)
		std::cout << GREEN "[Serializer] Successful" RESET << std::endl;
	else
		return std::cout << RED "[Serializer] Failed" RESET << std::endl, 1;

	std::cout << BLUE "Oiginal Ptr:\n" RESET << data << std::endl;
	std::cout << MAGENTA "Serialized Ptr:\n" RESET << *deserializeTest << std::endl;

	return (0);
}
