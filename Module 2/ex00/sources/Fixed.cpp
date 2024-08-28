/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/18 19:16:09 by ddania-c         ###   ########.fr       */
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

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
	return ;
}

/******************************OPERATOR****************************************/

Fixed	& Fixed::operator=(Fixed const & other) {
	std::cout << "Copy assignation operator called\n";
	if (this != &other)
		this->_raw = other.getRawBits();
	return (*this);
}

/******************************GETTERS*****************************************/

int	Fixed::getRawBits ( void ) const {
	std::cout << "getRawBits member function called\n";
	return (this->_raw);
}

/******************************SETTERS*****************************************/

void	Fixed::setRawBits (int const raw) {
	std::cout << "setRawBits member function called\n";
	this->_raw = raw;
	return ;
}
