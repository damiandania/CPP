/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:10:32 by ddania-c          #+#    #+#             */
/*   Updated: 2024/05/01 16:37:44 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <dirent.h>

class BitcoinExchange {
	private:
		std::map<std::string, float> _data;

		BitcoinExchange(void);

		void	_manageDataFile(std::string const& dataFile);
		bool	_isDirectory(std::string const& path);
		void	_executeExchange(std::string const& inputFile);
		bool	_checkDateFormat( std::string const& string ) const;
		bool	_checkValueFormat( std::string const& string ) const;
		bool	_checkInput(std::string const& date, std::string const& sep,
			std::string const& value, float const& valFloat, std::string const& error) const;
		void	_printRate(std::string const& date, float const& value) const;

	public:
		BitcoinExchange(std::string const& dataFile, std::string const& inputFile);
		BitcoinExchange(BitcoinExchange const& source);
		~BitcoinExchange(void);

		BitcoinExchange &  operator=(BitcoinExchange const& source);
};

#endif
