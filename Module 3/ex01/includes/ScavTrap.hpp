/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/08 23:57:52 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	private:
		ScavTrap(void);

	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & source);
		~ScavTrap(void);

		ScavTrap &	operator=(ScavTrap const & source);

		void		attack(std::string const & target);
		void		guardGate(void);
};

#endif
