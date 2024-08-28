/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/21 15:03:53 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Colors.h"

class	AAnimal {
	protected:
		std::string	_type;

	public:
		AAnimal(void);
		AAnimal(std::string const & type);
		AAnimal(AAnimal const & source);
		virtual ~AAnimal(void);

		AAnimal &	operator=(AAnimal const & source);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
