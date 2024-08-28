/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/24 13:06:51 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class Span {
	private:
		std::vector<int>	_vec;
		unsigned int		_maxSize;

		class	FewElementsException : public std::exception {
			public:
				virtual const char *	what(void) const throw() {
					return "Error: Index out of limits";
				};
		};
		class	maxSizeException : public std::exception {
			public:
				virtual const char *	what(void) const throw() {
					return "Error: Span is full, cannot add more numbers";
				};
		};

	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const & source);
		~Span(void);

		Span &	operator=(Span const & source);

		std::vector<int> const &	getVector(void) const;
		unsigned int				getMaxSize(void) const;

		void	addNumber(int nb);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addRange(std::vector<int>::iterator begin,
				std::vector<int>::iterator end);
};

std::ostream & operator<<(std::ostream & os, Span const & source);

#endif
