/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/02/21 14:19:59 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <cstdlib>
#include <iomanip>
#include <string>

/******************************CONSTRUCTORS************************************/

PhoneBook::PhoneBook(void) : _index(-1) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

/******************************ADD*CONTACT*************************************/

std::string PhoneBook::trimSpaces(std::string input) {
	size_t	start = input.find_first_not_of(" \t\n\r\f\v");
	size_t	end = input.find_last_not_of(" \t\n\r\f\v");

	if (start == std::string::npos || end == std::string::npos) {
		return ("");
	}

	return (input.substr(start, end - start + 1));
}

std::string	PhoneBook::_getInput(std::string message) {
	std::string	input;

	std::cout << message;
	if (!std::getline(std::cin, input))
		exit (1);
	input = trimSpaces(input);

	return (input);
}

void	PhoneBook::_nextIndex() {
	_index++;
	if (_index >= 8)
		_index = 0;
}

bool	PhoneBook::addContact() {
	system("clear");
	std::string	input;

	std::cout	<<"+----------ADD----------+\n";
	_nextIndex();
	while (1) {
		input = _getInput("FIRST NAME: ");
		if (this->_contactList[_index].setFirstName(input))
			break ;
	}
	while (1) {
		input = _getInput("LAST NAME: ");
		if (this->_contactList[_index].setLastName(input))
			break ;
	}
	while (1) {
		input = _getInput("NICKNAME: ");
		if (this->_contactList[_index].setNickName(input))
			break ;
	}
	while (1) {
		input = _getInput("PHONE NUMBER: ");
		if (this->_contactList[_index].setPhoneNumber(input))
			break ;
	}
	while (1) {
		input = _getInput("DARKEST SECRET: ");
		if (this->_contactList[_index].setDarkestSecret(input))
			break ;
	}
	std::cout << "\033[1;32mContact added...\n\033[0m";
	return (true);
}

/******************************SEARCH*CONTACT**********************************/

void	PhoneBook::_printData(std::string data) {
	if (data.length() > 10) {
		data.resize(9);
		std::cout << std::setw(9) << std::left << data << "." << "|";
	}
	else
		std::cout << std::setw(10) << std::left << data << "|";
	return ;
}

void	PhoneBook::_printContact(int i) {
	if (this->_contactList[i].itsEmpty())
		return ;
	std::cout << "|" << std::setw(10) << std::left << i << "|";
	_printData(this->_contactList[i].getFirstName());
	_printData(this->_contactList[i].getLastName());
	_printData(this->_contactList[i].getNickName());
	std::cout << std::endl;
	return ;
}

void	PhoneBook::_showContactList() {
	std::cout	<< "|INDEX     |FIRST NAME|LAST NAME |NICKNAME  |\n";
	for (int i = 0; i < 8; i++) {
		_printContact(i);
	}
	std::cout	<< "+----------+----------+----------+----------+\n";
}

void	PhoneBook::_showContactInfo(std::string input) {
	int	i;

	if (input.length() == 1 && std::isdigit(input[0])) {
		i = input[0] - '0';
		if (i >= 0 && i <= 7 && !this->_contactList[i].getFirstName().empty()) {
			std::cout << "\n\033[1;32mCONTACT INFO:\n\033[0m"
			<< "FIRST NAME: " << this->_contactList[i].getFirstName() << "\n"
			<< "LAST NAME: " << this->_contactList[i].getLastName() << "\n"
			<< "NICKNAME: " << this->_contactList[i].getNickName() << "\n"
			<< "PHONE NUMBER: " << this->_contactList[i].getPhoneNumber() << "\n"
			<< "DARKEST SECRET: " << this->_contactList[i].getDarkestSecret() << "\n";
		}
		else
			std::cout << "\033[1;31mError: wrong index...\n\033[0m";
	}
	else {
		std::cout << "\033[1;31mError: wrong index...\n\033[0m";
	}
	return ;
}

bool	PhoneBook::seachContact() {
	std::string	input;

	system("clear");
	std::cout << "+----------+-------SEARCH--------+----------+\n";
	if (_index == -1) {
		std::cout << "\033[1;31mNo contacts in the directory...\n\033[0m";
		return (true);
	}
	this->_showContactList();
	std::cout << "Enter an index number: ";
	std::getline(std::cin, input);;
	this->_showContactInfo(input);
	return (true);
}
