/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/15 19:16:44 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
	private:
		T *				_array;
		unsigned int	_size;

	public:
		class IndexOutOfLimits : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("[Exception] Index out of limits");
				}
		};

		Array() : _array(NULL), _size(0) {};
		Array(unsigned int n) : _array(new T[n]), _size(n) {};
		Array(Array const & source) : _array(new T[source._size]), _size(source._size) {
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = source._array[i];
			}
		}
		~Array() {delete [] _array;}

		Array & operator=(Array const & source) {
			if (this == &source)
				return *this;
			if (this->_size != source._size) {
				delete [] _array;
				this->_array = new T[source._size];
				this->_size = source._size;
			}
			for (unsigned int i = 0; i < source._size; i++) {
				this->_array[i] = source._array[i];
			}
			return *this;
		}

		T & operator[](unsigned int i) {
			if (i >= this->_size)
				throw IndexOutOfLimits();
			return this->_array[i];
		}

		unsigned int getSize() {
			return this->_size;
		}
};

template<typename T>
std::ostream & operator<<(std::ostream & os, Array<T> & source) {
	std::cout << "Array[";
	for (unsigned int i = 0; i < source.getSize(); i++) {
		os << source[i];
		if (i + 1 != source.getSize())
			std::cout << ", ";
	}
	std::cout << "]";
	return os;
}

#endif
