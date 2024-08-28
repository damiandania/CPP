/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:05 by ddania-c          #+#    #+#             */
/*   Updated: 2024/04/15 13:54:22 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class Serializer {
	private:
		static char const	_charMax;
		static char const	_charMin;
		static int const	_intMax;
		static int const	_intMin;

		Serializer(void);
		Serializer(Serializer const & source);
		~Serializer(void);

		Serializer &	operator=(Serializer const & source);

		static bool	_checkChar(std::string const str);
		static bool	_checkFloat(std::string const str);
		static bool	_checkInt(std::string const str);
		static bool	_checkDouble(std::string const str);

		static void	_printChar(char const c);
		static void	_printInt(int const i);
		static void	_printFloat(float const f);
		static void	_printDouble(double const d);
		static void _printImpossible(std::string type);

		static bool	_floatPseudoLiterals(std::string const str);
		static bool	_doublePseudoLiterals(std::string const str);
		static bool	_intDigits(std::string const str);
		static bool	_doubleDigits(std::string const str);

	public:
		static void converter(std::string const str);
};

#endif
