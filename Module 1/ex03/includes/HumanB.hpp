/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:27 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/18 18:16:08 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon*		_weapon;
		std::string	_name;

	public:
		HumanB(std::string name);
		~HumanB(void);

		void		attack(void) const;
		void		setWeapon(Weapon & weapon);
};

#endif
