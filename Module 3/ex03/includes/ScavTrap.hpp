/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/20 13:23:32 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define ST_HIT_POINTS 100
#define ST_ENERGY_POINTS 50
#define ST_ATTACK_DAMAGE 20

class	ScavTrap : virtual public ClapTrap {
	protected:
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
