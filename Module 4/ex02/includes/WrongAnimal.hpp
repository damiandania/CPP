/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/16 23:09:30 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongANIMAL_HPP
#define WRONGWrongANIMAL_HPP

#include <iostream>
#include "Colors.h"

class	WrongAnimal {
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string const & type);
		WrongAnimal(WrongAnimal const & source);
		virtual ~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & source);

		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
