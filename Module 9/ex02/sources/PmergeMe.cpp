/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:17:21 by damian            #+#    #+#             */
/*   Updated: 2024/05/01 15:30:26 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/******************************CONSTRUCTORS************************************/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> & vec, std::list<int> & lst) :
		_vec(vec), _lst(lst) {
	_printVecSeq("Before");
	_sequenceJacobsthal();
	_sortVector(vec);
	_sortList(lst);
}

PmergeMe::PmergeMe(PmergeMe const& src) : _vec(src._vec), _lst(src._lst) {}

PmergeMe::~PmergeMe() {}

/******************************OPERATORS***************************************/

PmergeMe & PmergeMe::operator=(PmergeMe const& src) {
	if (this != &src) {
		this->_vec = src._vec;
		this->_lst = src._lst;
	}
	return *this;
}

/******************************PRIVATE*****************************************/

void PmergeMe::_sequenceJacobsthal() {
	int nb = 20;

	std::vector<int> sequence(nb);

	for (int i = 0; i < nb; i++)
		sequence[i] = _startSequence(i);
	for (int i = 2; i < nb - 1; i++)
		_jacobsthalVec.push_back(sequence[i + 1] - sequence[i]);
}

int PmergeMe::_startSequence(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (_startSequence(n - 1) + 2 * _startSequence(n - 2));
}

void PmergeMe::_printVecSeq(std::string message) {
	std::cout << message << ": ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::_printLstSeq(std::string message) {
	std::cout << message << ": ";
for (std::list<int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
	std::cout << *it << " ";
}
std::cout << std::endl;
}

void PmergeMe::_printProcessTime(clock_t time, std::string type) {
	time = (clock() - time) * 100;

	std::cout << "Time to process a range of " << std::setw(4) << _vec.size()
		<< " elements with std::" << type << " : ";
	std::cout << std::setprecision(5) << std::fixed
		<< (static_cast<double>(time)) / CLOCKS_PER_SEC << " us" << std::endl;
}

/******************************PUBLIC******************************************/

static bool comparePair(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second < b.second;
}

/******************************VECTOR******************************************/

void PmergeMe::_sortVector(std::vector<int> & vec) {
	clock_t time = clock();

	_splitAndSortPairs(_vec);
	_vec.clear();
	_vec.push_back(_vecPair[0].first);

	for (size_t i = 0; i < _vecPair.size(); i++)
		_vec.push_back(_vecPair[i].second);

	_insertPends(vec);
	_printVecSeq("After");
	_printProcessTime(time, "vector");
}

void PmergeMe::_splitAndSortPairs(std::vector<int> & vec) {
	if (vec.size() < 2)
		return;
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (i + 1 < vec.size())
			_vecPair.push_back(std::make_pair(std::min(vec[i], vec[i + 1]),
				std::max(vec[i], vec[i + 1])));
	}
	std::sort(_vecPair.begin(), _vecPair.end(), comparePair);
}

void PmergeMe::_addPends(std::vector<int> & pends, std::vector<int> & vec) {
	for (size_t i = 1; i < _vecPair.size(); i++)
		pends.push_back(_vecPair[i].first);
	if (vec.size() % 2 == 1)
		pends.push_back(vec[vec.size() - 1]);
}

void PmergeMe::_insertPends(std::vector<int>& vec) {
	std::vector<int> pends;
	_addPends(pends, vec);

	std::vector<int>::iterator itPends = pends.begin();
	std::vector<int>::iterator it;

	for (size_t i = 0; i < _jacobsthalVec.size(); i++) {
		for (size_t j = 0; j < _jacobsthalVec[i] && itPends != pends.end(); j++) {
			it = upper_bound(_vec.begin(), _vec.end(), *itPends);
			_vec.insert(it, *itPends);
			itPends++;
		}
	}
}

/******************************LIST********************************************/

void PmergeMe::_sortList(std::list<int> & lst) {
	clock_t time = clock();

	_splitAndSortPairs(_lst);
	_lst.clear();
	_lst.push_back(_lstPair.front().first);

	for (std::list<std::pair<int, int> >::iterator it = _lstPair.begin();
			it != _lstPair.end(); it++) {
		_lst.push_back((*it).second);
	}

	_insertPends(lst);
	// _printVecSeq("list");
	_printProcessTime(time, "list");
}

void PmergeMe::_splitAndSortPairs(std::list<int> & lst) {
	if (lst.size() < 2) {
		return;
	}
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end()) {
		int first = *it;
		it++;

		if (it != lst.end()) {
			int second = *it;
			_lstPair.push_back(std::make_pair(std::min(first, second),
				std::max(first, second)));
			it++;
		}
	}
	_lstPair.sort(comparePair);
}

void PmergeMe::_addPends(std::list<int> & pends, std::list<int> & lst) {
	for (std::list<std::pair<int, int> >::iterator it = _lstPair.begin();
			it != _lstPair.end(); it++)
		pends.push_back((*it).second);
	if (lst.size() % 2 == 1)
		pends.push_back(lst.back());
}

void PmergeMe::_insertPends(std::list<int>& lst) {
	std::list<int> pends;
	_addPends(pends, lst);

	std::list<int>::iterator itPends = pends.begin();
	std::list<int>::iterator it;

	for (size_t i = 0; i < _jacobsthalVec.size(); i++) {
		for (size_t j = 0; j < _jacobsthalVec[i] && itPends != pends.end(); j++) {
			it = std::upper_bound(_lst.begin(), _lst.end(), *itPends);
			_lst.insert(it, *itPends);
			itPends++;
		}
	}
}
