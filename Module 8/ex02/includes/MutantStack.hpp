/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/23 21:37:20 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template < typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
	public:
		MutantStack(void) : std::stack<T, C>() {};
		MutantStack (MutantStack & source) : std::stack<T, C>(source) {};
		~MutantStack (void) {};

		MutantStack &	operator=(MutantStack<T, C> const & source) {
			if (this != &source)
				this->c = source.c;
			return *this;
		};

		typedef typename C::iterator				iterator;
		typedef typename C::const_iterator			const_iterator;
		typedef typename C::reverse_iterator		reverse_iterator;
		typedef typename C::const_reverse_iterator	const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		const_iterator begin () const { return this->c.begin(); }
		const_iterator end () const { return this->c.end(); }

		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
