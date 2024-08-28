/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:39:19 by damiandania       #+#    #+#             */
/*   Updated: 2024/04/15 15:35:19 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

char const	Serializer::_charMax = std::numeric_limits<char>::max();
char const	Serializer::_charMin = std::numeric_limits<char>::min();
int const	Serializer::_intMax = std::numeric_limits<int>::max();
int const	Serializer::_intMin = std::numeric_limits<int>::min();

/******************************CONSTRUCTORS************************************/

Serializer::Serializer(void) {
	std::cout << GREEN "[ScalarConverter] constructor default is called\n" RESET;
	return ;
}

Serializer::Serializer(Serializer const & source) {
	std::cout << GREEN "[ScalarConverter] copy is called\n" RESET;
	(void)source;
	return ;
}

Serializer::~Serializer(void) {
	std::cout << BLUE "[ScalarConverter] destructor is called\n" RESET;
	return ;
}

/******************************OPERATORS***************************************/

Serializer & Serializer::operator=(Serializer const & source) {
	std::cout << GREEN "[ScalarConverter] assignment operator is called\n" RESET;
	(void)source;
	return (*this);
}

/******************************PRINT*******************************************/

void Serializer::_printChar(char const c) {
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void Serializer::_printInt(int const i) {
	std::cout << "int: "<< std::fixed << std::setprecision(1) << i << std::endl;
}

void Serializer::_printFloat(float const f) {
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" <<std::endl;
}

void Serializer::_printDouble(double const d) {
	std::cout << "double: " << d << std::endl;

}

void Serializer::_printImpossible(std::string type) {
	std::cout << type << ": impossible" << std::endl;
}

/******************************CHECK*******************************************/

bool Serializer::_floatPseudoLiterals(std::string const str) {
	return (str == "+inff" || str == "-inff" || str == "nanf");
}

bool Serializer::_doublePseudoLiterals(std::string const str) {
	return (str == "+inf" || str == "-inf" || str == "nan");
}

bool Serializer::_intDigits(std::string const str) {
	int sign = 0;

	if (str[0] == '-' || str[0] == '+')
		sign++;

	for (size_t i = sign; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool Serializer::_doubleDigits(std::string const str) {
	int i = 0;
	int point = 0;

	if (_doublePseudoLiterals(str))
		return true;
	if (str[i] == '-' || str[i] == '+')
			i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == '.' && str[i + 1])
				point++;
			else
				return (false);
		}
		i++;
	}
	if (!str[i] && point == 1)
		return (true);
	return (false);
}

bool Serializer::_checkChar(std::string const str) {

	if (str.size() == 1 && std::isalpha(str[0])) {
		char c = str[0];
		_printChar(c);
		_printInt(static_cast<int>(c));
		_printFloat(static_cast<float>(c));
		_printDouble(static_cast<double>(c));
		return true;
	}
	return false;
}

bool Serializer::_checkFloat(std::string const str) {
	float f;
	char* endStr;

	f = strtof(str.c_str(), &endStr);

	if (*endStr == 'f' && endStr == (str.c_str() + str.length() - 1)) {
		if (f > _charMax || f < _charMin || _floatPseudoLiterals(str))
			_printImpossible("char");
		else
			_printChar(static_cast<char>(f));
		if (f > _intMax || f < _intMin || _floatPseudoLiterals(str))
			_printImpossible("int");
		else
			_printInt(static_cast<int>(f));
		_printFloat(f);
		_printDouble(static_cast<double>(f));
		return true;
	}
	return false;
}

bool Serializer::_checkDouble(std::string const str) {
	if (_doubleDigits(str) && strtod(str.c_str(), NULL)) {
		double d = strtod(str.c_str(), NULL);
		if (d > _charMax || d < _charMin || _doublePseudoLiterals(str))
			_printImpossible("char");
		else
			_printChar(static_cast<char>(d));
		if (d > _intMax || d < _intMin || _doublePseudoLiterals(str))
			_printImpossible("int");
		else
			_printInt(static_cast<int>(d));
		_printFloat(static_cast<float>(d));
		_printDouble(d);
		return true;
	}
	return false;
}

bool Serializer::_checkInt(std::string const str) {
	long ln;
	ln = std::strtol(str.c_str(), NULL, 10);
	if (_intDigits(str) && ln > _intMin && ln < _intMax) {
		if (ln > _charMax || ln < _charMin)
			_printImpossible("char");
		else
			_printChar(static_cast<char>(ln));
		_printInt(static_cast<int>(ln));
		_printFloat(static_cast<float>(ln));
		_printDouble(static_cast<double>(ln));
		return true;
	}
	return false;
}

/******************************CONVERTER***************************************/

void Serializer::converter(std::string const str) {
	if (str.empty()) {
		std::cout << "Empty argument" << std::endl;
		return ;
	}
	else if (_checkChar(str))
		return ;
	else if (_checkInt(str))
		return ;
	else if (_checkFloat(str))
		return ;
	else if (_checkDouble(str))
		return ;
	else {
		_printImpossible("char");
		_printImpossible("int");
		_printImpossible("float");
		_printImpossible("double");
		return ;
	}
}
