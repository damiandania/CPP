/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:28:19 by ddania-c          #+#    #+#             */
/*   Updated: 2024/02/21 14:28:20 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/******************************CONSTRUCTORS************************************/

Account::Account( int initial_deposit ) :	_amount(initial_deposit),
											_nbDeposits(0),
											_nbWithdrawals(0) {
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex
				<< ";amount:"	<< initial_deposit
				<< ";created\n";
	return ;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex
				<< ";amount:"		<< this->_amount
				<< ";closed"		<< std::endl;
	_nbAccounts--;
	_totalAmount -= this->_amount;
	return ;
}

/******************************GETTER******************************************/

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

 int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

/******************************PRIVATE*****************************************/

void	Account::_displayTimestamp( void ) {
	std::time_t	currentTime = std::time(&currentTime);
	std::tm		*localTime = std::localtime(&currentTime);

	char		buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);

	std::cout << "[" << buffer << "] ";
	return ;
}

/******************************PUBLIC******************************************/

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout	<< "accounts:"		<< getNbAccounts()
				<< ";total:"		<< getTotalAmount()
				<< ";deposits:"		<< getNbDeposits()
				<< ";withdrawals:"	<< getNbWithdrawals()
				<< std::endl;
	return ;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex
				<< ";p_amount:"		<< this->_amount
				<< ";deposit:"		<< deposit;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout	<< ";amount:"		<< this->_amount
				<< ";nb_deposits:"	<< ++this->_nbDeposits
				<< "\n";
	Account::_totalNbDeposits++;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex
				<< ";p_amount:"		<< this->_amount;
	if (withdrawal > this->_amount) {
		std::cout	<< ";withdrawal:refused\n";
	}
	else {
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout	<< ";withdrawal:"	<< withdrawal
					<< ";amount:"		<< this->_amount
					<< ";nb_withdrawals:"<< ++this->_nbWithdrawals
					<< "\n";
		Account::_totalNbWithdrawals++;
	}
	return (true);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex
				<< ";amount:"		<< this->_amount
				<< ";deposits:"		<< this->_nbDeposits
				<< ";withdrawals:"	<< this->_nbWithdrawals
				<< "\n";
	return ;
}
