/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:22:30 by damian            #+#    #+#             */
/*   Updated: 2024/03/18 17:08:16 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main (int ac, char **av) {
	std::string		s1;
	std::string		s2;
	std::string		line;

	if (ac != 4) {
		std::cerr << "Error: it must have 3 parameters\n";
		return (1);
	}
	std::string archivo = av[1];
	std::ifstream inFile(archivo.c_str());
	if (!inFile.is_open()) {
		std::cerr << "Error: cannot open the file\n";
		return (1);
	}

	s1 = av[2];
	if (s1.empty()) {
		std::cerr << "Error: string 1 is empty\n";
		return (1);
	}

	s2 = av[3];
	if (s2.empty()) {
		std::cerr << "Error: string 2 is empty\n";
		return (1);
	}

	if (s1 == s2){
		std::cerr << "Error: string 1 is the same as string 2\n";
		return (1);
	}

	std::ofstream outFile((archivo + ".replace").c_str());

	while (std::getline(inFile, line)) {
		size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outFile << line << std::endl;
	}

	inFile.close();
	outFile.close();

	std::cout << "The file has been modified\n";

	return (0);
}
