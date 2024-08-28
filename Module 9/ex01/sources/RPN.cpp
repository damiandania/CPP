/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:32:58 by damian            #+#    #+#             */
/*   Updated: 2024/05/01 14:09:20 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/******************************CONSTRUCTORS************************************/

RPN::RPN(void) {}

RPN::RPN(std::string const& input) {
	_calculate(input);
}

RPN::RPN(RPN const& source) : _stack(source._stack) {}

RPN::~RPN(void) {}

/******************************OPERATORS***************************************/

RPN & RPN::operator=(RPN const& source) {
	if (this != &source)
		this->_stack = source._stack;
	return *this;
}

/******************************PRIVATE*****************************************/

void RPN::_calculate(std::string const& input) {
	std::istringstream iss(input);
	std::string token;

	while (iss >> token) {
		if (isdigit(token[0]) && token.size() == 1) {
			_stack.push(atoi(token.c_str()));
		}
		else if (_isOperator(token[0]) && token.size() == 1) {
			if (_stack.size() < 2)
				throw std::invalid_argument("Insufficient numbers");
			long int operand2 = _stack.top();
			_stack.pop();
			long int operand1 = _stack.top();
			_stack.pop();
			long int result = _applyOperator(token[0], operand1, operand2);
			_stack.push(result);
		}
		else {
			throw std::invalid_argument("Invalid token → " + token);
		}
	}
	return ;
}

bool RPN::_isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

long int RPN::_applyOperator(char op, long int operand1, long int operand2) {
	switch (op) {
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			if (operand2 == 0) {
				throw std::invalid_argument("Division by zero");
			}
			return operand1 / operand2;
		default:
			throw std::invalid_argument("Unknown operator");
	}
}

/******************************PUBLIC******************************************/

long int RPN::getResult() {
	if (_stack.size() != 1)
		throw std::invalid_argument("Insufficient operators");
	if (_stack.top() > 2147483647 || _stack.top() < -2147483648)
		throw std::out_of_range("Value out of range");
	return _stack.top();
}
