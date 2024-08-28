/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:28:15 by damian            #+#    #+#             */
/*   Updated: 2024/05/01 15:06:20 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::list<int>		_lst;
		std::vector<size_t>	_jacobsthalVec;

		std::vector< std::pair<int, int> >	_vecPair;
		std::list< std::pair<int, int> >	_lstPair;

		PmergeMe(void);

		void	_sequenceJacobsthal(void);
		int		_startSequence(int n);
		void	_printVecSeq(std::string message);
		void	_printLstSeq(std::string message);
		void	_printProcessTime(clock_t time, std::string type);

		void	_sortVector(std::vector<int> & vec);
		void	_splitAndSortPairs(std::vector<int> & _vec);
		void	_insertPends(std::vector<int> & vec);
		void	_addPends(std::vector<int> & pends, std::vector<int> & vec);

		void	_sortList(std::list<int> & lst);
		void	_splitAndSortPairs(std::list<int> & _lst);
		void	_insertPends(std::list<int> & lst);
		void	_addPends(std::list<int> & pends, std::list<int> & lst);

	public:
		PmergeMe(std::vector<int> & vec, std::list<int> & lst);
		PmergeMe(PmergeMe const& src);
		~PmergeMe(void);

		PmergeMe & operator=(PmergeMe const& src);
};

#endif

