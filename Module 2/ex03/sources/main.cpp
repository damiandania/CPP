/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:16 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/19 13:42:35 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
	Fixed x1(1.0f), y1(1.0f);
	Fixed x2(4.0f), y2(1.0f);
	Fixed x3(2.5f), y3(4.0f);

	Point a(x1, y1);
	Point b(x2, y2);
	Point c(x3, y3);

	Fixed px(1.1f), py(1.1f);
	Point point(px, py);

	bool isInside = bsp(a, b, c, point);

	std::cout << "The point (" << px.toFloat() << ", " << py.toFloat() << ") ";
	if (isInside == true)
		std::cout << "is " GREEN "INSIDE" RESET " the triangle...\n";
	else
		std::cout << "is " RED "OUTSIDE" RESET " the triangle.\n";

	return 0;
}
