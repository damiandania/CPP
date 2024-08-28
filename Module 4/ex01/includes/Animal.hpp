/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/21 15:37:47 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Colors.h"

class	Animal {
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(std::string const & type);
		Animal(Animal const & source);
		virtual ~Animal(void);

		Animal &	operator=(Animal const & source);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
