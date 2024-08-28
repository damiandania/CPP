/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/05 21:44:54 by damian           ###   ########.fr       */
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
		Fixed(Fixed const & origin);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();

		Fixed &	operator=(Fixed const & fixed);

		bool	operator>(Fixed const & fixed) const;
		bool	operator<(Fixed const & fixed) const;
		bool	operator>=(Fixed const & fixed) const;
		bool	operator<=(Fixed const & fixed) const;
		bool	operator==(Fixed const & fixed) const;
		bool	operator!=(Fixed const & fixed) const;

		Fixed	operator+(Fixed const & fixed) const;
		Fixed	operator-(Fixed const & fixed) const;
		Fixed	operator*(Fixed const & fixed) const;
		Fixed	operator/(Fixed const & fixed) const;

		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed &			max(Fixed & fixA, Fixed & fixB);
		static Fixed const &	max(Fixed const & fixA, Fixed const & fixB);
		static Fixed &			min(Fixed & fixA, Fixed & fixB);
		static Fixed const &	min(Fixed const & fixA, Fixed const & fixB);
};

std::ostream & operator<<(std::ostream & os, Fixed const & src);

#endif
