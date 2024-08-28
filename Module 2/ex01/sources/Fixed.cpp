/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/18 19:14:47 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/******************************CONSTRUCTORS************************************/

Fixed::Fixed(void) : _raw(0) {
	std::cout << "Default constructor called\n";
	return ;
}

Fixed::Fixed(const Fixed & origin) {
	std::cout << "Copy constructor called\n";
	*this = origin;
	return ;
}

Fixed::Fixed(const int value) : _raw(value << _fracBits) {
	std::cout << "Int constructor called\n";
	return ;
}

Fixed::Fixed(const float value) :  _raw(roundf(value * (1 << _fracBits))) {
	std::cout << "Float constructor called\n";
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
	return ;
}

/******************************OPERATORS***************************************/

Fixed	& Fixed::operator=(Fixed const & other) {
	std::cout << "Copy assignation operator called\n";
	if (this != &other)
		this->_raw = other.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & os, Fixed const & src) {
	os << src.toFloat();
	return (os);
}

/******************************GETTERS*****************************************/

int	Fixed::getRawBits ( void ) const {
	return (this->_raw);
}

/******************************SETTERS*****************************************/

void	Fixed::setRawBits (int const raw) {
	std::cout << "setRawBits member function called\n";
	this->_raw = raw;
	return ;
}

/******************************PUBLIC******************************************/

int		Fixed::toInt( void ) const {
	return (this->_raw >> _fracBits);
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_raw  / (1 << _fracBits));
}
