/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/15 16:23:35 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T & x, T & y) {
	T aux;

	aux = x;
	x = y;
	y = aux;
	return ;
}

template<typename T>
T const & min(T const & x, T const & y) {
	return (x < y ? x : y);
}

template<typename T>
T const & max(T const & x, T const & y) {
	return (x > y ? x : y);
}

#endif
