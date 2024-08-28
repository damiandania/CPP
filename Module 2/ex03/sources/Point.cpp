/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/05 19:39:25 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include "../includes/Fixed.hpp"

/******************************CONSTRUCTORS************************************/

Point::Point(void) : _x(0), _y(0) {
	return ;
}

Point::Point(Point const & ori) : _x(ori.getPointX()), _y(ori.getPointY()){
	return ;
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {
	return ;
}

Point::~Point(void) {
	return ;
}

/******************************OPERATORS***************************************/

Point &	Point::operator=(Point const & point) {
	(void)point;
	return (*this);
}

/******************************GETTERS*****************************************/

Fixed const &	Point::getPointX ( void ) const {
	return (this->_x);
}

Fixed const &	Point::getPointY ( void ) const {
	return (this->_y);
}
