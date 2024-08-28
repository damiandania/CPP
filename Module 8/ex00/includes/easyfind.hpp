/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/23 11:16:38 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>

class NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Element not found");
		}
};

template<typename T>
typename T::const_iterator easyfind(T const & container, int const toFind) {
	typename T::const_iterator	it;

	it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif
