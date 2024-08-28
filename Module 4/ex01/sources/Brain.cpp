/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:39:19 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/21 12:55:01 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include <fstream>
#include <string>

/******************************CONSTRUCTORS************************************/

Brain::Brain(std::string const type) {
	std::cout << GREEN "[Brain] constructor is called" RESET "\n";
	addIdeas(type);
	return ;
}

Brain::Brain(Brain const & source) {
	std::cout << GREEN "[Brain] copy is called" RESET "\n";
	*this = source;
	return ;
}

Brain::~Brain(void) {
	std::cout << RED "[Brain] destructor is called"	RESET "\n";
	return ;
}

/******************************OPERATORS***************************************/

Brain &	Brain::operator=(Brain const & source) {
	if (this != &source) {
		for (int i = 0; i < NB_IDEAS; i++)
			this->_ideas[i] = source.getIdea(i);
	}
	return (*this);
}

/******************************GETTERS*****************************************/

std::string	Brain::getIdea ( int i ) const {
	if (i > 99 || i < 0)
		return ("No idea(out of range)");
	return (this->_ideas[i]);
}

/******************************PRIVATE*****************************************/

void	Brain::addIdeas(std::string const type) {
	std::ifstream	file("ideas.txt");
	std::string		idea;
	int				i = 0;

	if (!file.is_open()) {
		std::cerr << RED "[Brain] Error: cannot open Ideas.txt" RESET "\n";
		return ;
	}

	while (std::getline(file, idea) && i < NB_IDEAS) {
		_ideas[i++] = type + " " + idea;
	}

	file.close();

	return ;
}
