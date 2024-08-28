/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/02 22:21:24 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ieee754.h>

class	Fixed {
	private:
		int					_raw;
		static const int	_fracBits = 8;

	public:
		Fixed();
		Fixed(const Fixed & origin);
		~Fixed();

		Fixed &	operator=(Fixed const & other);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );


};

#endif
