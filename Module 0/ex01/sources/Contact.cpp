/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:13 by ddania-c          #+#    #+#             */
/*   Updated: 2024/02/21 10:58:14 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

/******************************CONSTRUCTORS************************************/

Contact::Contact(): _firstname(""), _lastname(""), _nickname(""),
		_phonenumber(""), _darkestsecret("") {
	return ;
}

Contact::~Contact() {
	return ;
}

/******************************GETTERS*****************************************/

std::string	Contact::getFirstName() {
	return (this->_firstname);
}

std::string	Contact::getLastName() {
	return (this->_lastname);
}

std::string	Contact::getNickName() {
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber() {
	return (this->_phonenumber);
}

std::string	Contact::getDarkestSecret() {
	return (this->_darkestsecret);
}

/******************************SETTERS*****************************************/

bool	Contact::setFirstName(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_itsOnlyLetters(str)) {
		std::cout << "\033[1;31mError: only letters allowed\n\033[0m";
		return (false);
	}
	this->_firstname = str;
	return (true);
}

bool	Contact::setLastName(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_itsOnlyLetters(str)) {
		std::cout << "\033[1;31mError: only letters allowed\n\033[0m";
		return (false);
	}
	this->_lastname = str;
	return (true);
}

bool	Contact::setNickName(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_itsOnlyLetters(str)) {
		std::cout << "\033[1;31mError: only letters allowed\n\033[0m";
		return (false);
	}
	this->_nickname = str;
	return (true);
}

bool	Contact::setPhoneNumber(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_itsOnlyNumbers(str)) {
		std::cout << "\033[1;31mError: only numbers allowed\n\033[0m";
		return (false);
	}
	this->_phonenumber = str;
	return (true);
}

bool	Contact::setDarkestSecret(std::string str) {
	if (str.empty()) {
		return (false);
	}
	this->_darkestsecret = str;
	return (true);
}

/******************************PRIVATE*****************************************/

bool	Contact::_itsOnlyLetters(std::string input) {
	for (std::string::const_iterator i = input.begin(); i != input.end(); i++) {
		if (!std::isalpha(*i) && *i != ' ')
			return (false);
	}
	return (true);
}

bool	Contact::_itsOnlyNumbers(std::string input) {
	for (std::string::const_iterator i = input.begin(); i != input.end(); i++) {
		if (!std::isdigit(*i) && *i != '-')
			return (false);
	}
	return (true);
}

/******************************PUBLIC*****************************************/

bool	Contact::itsEmpty() {
	if (this->_firstname.empty())
		return (true);
	return (false);
}
