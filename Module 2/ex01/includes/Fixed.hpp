/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/02 22:50:35 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ieee754.h>
#include <cmath>

class	Fixed {
	private:
		int					_raw;
		static const int	_fracBits = 8;

	public:
		Fixed();
		Fixed(const Fixed & origin);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		Fixed &	operator=(Fixed const & other);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream & operator<<(std::ostream & os, Fixed const & src);

#endif
