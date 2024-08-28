/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/19 13:38:04 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

Fixed	crossProduct(Point const a, Point const b, Point const c) {
	return ((b.getPointX() - a.getPointX()) * (c.getPointY() - a.getPointY())
		- (b.getPointY() - a.getPointY()) * (c.getPointX() - a.getPointX()));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed d1(crossProduct(a, b, point));
	Fixed d2(crossProduct(b, c, point));
	Fixed d3(crossProduct(c, a, point));

	if ((d1 <= 0) || (d2 <= 0) || (d3 <= 0))
		return (false);
	return (true);
}
