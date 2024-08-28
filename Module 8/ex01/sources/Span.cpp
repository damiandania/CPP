/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:12:11 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/24 13:20:00 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

/******************************CONSTRUCTORS************************************/

Span::Span(void) : _vec(), _maxSize(0) {
	return ;
}

Span::Span(unsigned int N) : _vec(), _maxSize(N) {
	return ;
}

Span::Span(Span const & source) : _vec(source._vec), _maxSize(source._maxSize) {
	return ;
}

Span::~Span(void) {
	return ;
}

/******************************OPERATORS***************************************/

Span & Span::operator=(Span const & source) {
	if (this != &source) {
		this->_vec.clear();
		this->_vec.insert(this->_vec.end(), source._vec.begin(), source._vec.end());
		this->_maxSize = source._maxSize;
	}
	return *this;
}

std::ostream & operator<<(std::ostream & os, Span const &  source) {
	std::cout << "[";
	for (std::vector<int>::const_iterator it = source.getVector().begin();
			it != source.getVector().end(); it++) {
		os << *it;
		if (it + 1 != source.getVector().end())
			std::cout << ", ";
	}
	std::cout << "]";
	os << " Max size: " << source.getMaxSize();
	return os;
}

/******************************GETTER******************************************/

std::vector<int> const & Span::getVector(void) const {
	return this->_vec;
}

unsigned int Span::getMaxSize(void) const {
	return this->_maxSize;
}

/******************************PUBLIC******************************************/

void Span::addNumber(int nb) {
	if (this->_vec.size() >= this->_maxSize)
		throw maxSizeException();
	this->_vec.push_back(nb);
	return ;
}

int Span::shortestSpan() const {
	if (this->getVector().size() < 2)
		throw FewElementsException();

	std::vector<int> sorted(this->_vec);
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> spans(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), spans.begin());
	return *std::min_element(++(spans.begin()), spans.end());
}

int Span::longestSpan() const {
	if (this->_vec.size() < 2)
		throw FewElementsException();

	int min = *std::min_element(this->_vec.begin(), this->_vec.end());
	int max = *std::max_element(this->_vec.begin(), this->_vec.end());
	return max - min;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if ((std::distance(begin, end) + this->_vec.size()) > this->_maxSize)
		throw maxSizeException();
	this->_vec.insert(this->_vec.end(), begin, end);
	return ;
}
