/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:10:32 by ddania-c          #+#    #+#             */
/*   Updated: 2024/05/01 14:09:12 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class RPN {
	private:
		std::stack<long int>	_stack;

		RPN(void);

		void		_calculate(std::string const& input);
		bool		_isOperator(char c);
		long int	_applyOperator(char op, long int operand1, long int operand2);

	public:
		RPN(std::string const& input);
		RPN(RPN const& source);
		~RPN(void);

		RPN &  operator=(RPN const& source);

		long int	getResult();
};

#endif
