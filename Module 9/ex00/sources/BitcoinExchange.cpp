/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:32:58 by damian            #+#    #+#             */
/*   Updated: 2024/05/01 19:22:25 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/******************************CONSTRUCTORS************************************/

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string const& dataFile, std::string const& inputFile) {
	_manageDataFile(dataFile);
	_executeExchange(inputFile);
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& source) : _data(source._data) {}

BitcoinExchange::~BitcoinExchange(void) {}

/******************************OPERATORS***************************************/

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const& source) {
	if (this != &source)
		this->_data = source._data;
	return *this;
}

/******************************PRIVATE*****************************************/

void BitcoinExchange::_manageDataFile(std::string const& dataFile) {
	std::ifstream file;
	file.open(dataFile.c_str());

	if (_isDirectory(dataFile))
		throw std::runtime_error("The data file is a directory");
	if (!file.is_open())
		throw std::runtime_error("Can't open data file");
	if (dataFile.size() < 4 || dataFile.substr(dataFile.size() - 4) != ".csv")
		throw std::runtime_error("Data file is not a .csv");

	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Data file is empty");

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date, value;

		std::getline(iss, date, ',');
		std::getline(iss, value);

		if (!_checkDateFormat(date))
			throw std::runtime_error("Bad data → " + date);
		if (!_checkValueFormat(value))
			throw std::runtime_error("Bad data → " + value);

		float valFloat = std::atof(value.c_str());
		_data.insert(std::pair<std::string, float>(date, valFloat));
	}
	file.close();
}

bool BitcoinExchange::_isDirectory(std::string const& path) {
	DIR *dir = opendir(path.c_str());
	if (dir != NULL) {
		closedir(dir);
		return true;
	}
	return false;
}

void BitcoinExchange::_executeExchange(std::string const& inputFile) {
	std::ifstream file;
	file.open(inputFile.c_str());

	if (_isDirectory(inputFile))
		throw std::runtime_error("The input file is a directory");
	if (!file.is_open())
		throw std::runtime_error("Can't open input file");
	if (inputFile.size() < 4 || inputFile.substr(inputFile.size() - 4) != ".csv")
		throw std::runtime_error("Input file is not a .csv");
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Input file is empty");

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date, sep, value, error;

		iss >> date >> sep >> value >> error;
		float valFloat = std::atof(value.c_str());
		if (_checkInput(date, sep, value, valFloat, error))
			_printRate(date, valFloat);
	}
	file.close();
}

bool BitcoinExchange::_checkDateFormat(std::string const& date) const {
	if (date.empty() || date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return false;

	int monthlen[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && month == 2)
		monthlen[1] = 29;
	if (day > monthlen[month - 1])
		return false;
	if (month > 12)
		return false;
	return true;
}

bool BitcoinExchange::_checkInput(std::string const& date, std::string const& sep,
		std::string const& value, float const& valFloat, std::string const& error) const {
	if (!_checkDateFormat(date))
		return (std::cout << "Error: bad input → " << date << std::endl, false);
	if (sep != "|")
		return (std::cout << "Error: bad separator → "
			<< (sep.empty() ? "no separator" : sep) << std::endl, false );
	if (valFloat < 0)
		return (std::cout << "Error: not a positive number." << std::endl, false);
	if (valFloat > 1000)
		return (std::cout << "Error: too large a number." << std::endl, false);
	if (!error.empty())
		return (std::cout << "Error: invalid value input → " << error
			<< std::endl, false);
	if (!_checkValueFormat(value))
		return (std::cout << "Error: invalid value input → " << value
			<< std::endl, false);
	return true;
}

bool BitcoinExchange::_checkValueFormat(std::string const& str) const {
	int dotCount = 0;

	if (str.empty() || str == "." || str[str.length() - 1] == '.')
		return false;

	for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (!std::isdigit(*it) && *it != '.')
			return false;
		if (*it == '.') {
			dotCount++;
			if (dotCount > 1)
				return false;
		}
	}
	return true;
}

void BitcoinExchange::_printRate(std::string const& date, float const& value) const {
	std::map<std::string, float>::const_iterator it;
	std::map<std::string, float>::const_iterator it2;

	it = _data.find(date);
	it2 = _data.lower_bound(date);

	if (it != _data.end())
		std::cout << date << " → " << value << " = " << value * it->second << std::endl;
	else if (it2 == _data.begin())
		std::cout << "Error: Data not available" << std::endl;
	else
		std::cout << date << " → " << value << " = " << value * (--it2)->second << std::endl;
	return ;
}
