/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/19 13:45:21 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/******************************CONSTRUCTORS************************************/

Fixed::Fixed(void) : _raw(0) {
	return ;
}

Fixed::Fixed(const Fixed & origin) {
	*this = origin;
	return ;
}

Fixed::Fixed(const int value) : _raw(value << _fracBits) {
	return ;
}

Fixed::Fixed(const float value) : _raw(roundf(value * (1 << _fracBits))) {
	return ;
}

Fixed::~Fixed(void) {
	return ;
}

/******************************OPERATORS***************************************/

Fixed	& Fixed::operator=(Fixed const & fixed) {
	if (this != &fixed)
		this->_raw = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const & fixed) const {
	if (this->_raw > fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const & fixed) const {
	if (this->_raw < fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const & fixed) const {
	if (this->_raw >= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const & fixed) const {
	if (this->_raw <= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const & fixed) const {
	if (this->_raw != fixed.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const & fixed) const {
	Fixed result(this->toFloat() + fixed.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const & fixed) const {
	Fixed result(this->toFloat() - fixed.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const & fixed) const {
	Fixed result(this->toFloat() * fixed.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const & fixed) const {
	Fixed result(this->toFloat() / fixed.toFloat());
	return (result);
}

Fixed &	Fixed::operator++(void) {
	this->_raw++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed result(*this);
	++(*this);
	return (result);
}

Fixed &	Fixed::operator--(void) {
	this->_raw--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed result(*this);
	--(*this);
	return (result);
}

std::ostream & operator<<(std::ostream & os, Fixed const & fixed) {
	os << fixed.toFloat();
	return (os);
}

/******************************GETTERS*****************************************/

int	Fixed::getRawBits ( void ) const {
	return (this->_raw);
}

/******************************SETTERS*****************************************/

void	Fixed::setRawBits (int const raw) {
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

Fixed &	Fixed::max(Fixed & fixA, Fixed & fixB) {
	if (fixA <= fixB)
		return (fixB);
	return (fixA);
}

Fixed const &	Fixed::max(Fixed const & fixA, Fixed const & fixB) {
	if (fixA <= fixB)
		return (fixB);
	return (fixA);
}

Fixed &	Fixed::min(Fixed & fixA, Fixed & fixB) {
	if (fixA >= fixB)
		return (fixB);
	return (fixA);
}

Fixed const &	Fixed::min(Fixed const & fixA, Fixed const & fixB) {
	if (fixA >= fixB)
		return (fixB);
	return (fixA);
}
