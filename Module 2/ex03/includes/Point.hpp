/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/19 13:36:33 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_PHH
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

class	Point {
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(Point const & origin);
		Point(Fixed const x, Fixed const y);
		~Point(void);

		Point &	operator=(Point const & point);

		Fixed const &	getPointX ( void ) const;
		Fixed const &	getPointY ( void ) const;
};

#endif
