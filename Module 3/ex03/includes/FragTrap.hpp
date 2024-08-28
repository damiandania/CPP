/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/20 13:23:28 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#define FT_HIT_POINTS 100
#define FT_ENERGY_POINTS 100
#define FT_ATTACK_DAMAGE 30

class	FragTrap : virtual public ClapTrap {
	protected:
		FragTrap(void);

	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const & source);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const & source);

		void		highFivesGuys(void);
};

#endif
