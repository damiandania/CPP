/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:16 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/20 13:49:56 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main( void ) {
	DiamondTrap	diego("Diego");
	std::cout << "\n";

	std::cout << "Diego hit points: " << diego.getHitPoints() << "\n";
	std::cout << "Diego energy points: " << diego.getEnergyPoints() << "\n";
	std::cout << "Diego attack points: " << diego.getAttackDamage() << "\n\n";

	diego.attack("Roy");
	diego.takeDamage(40);
	diego.beRepaired(25);
	diego.guardGate();
	diego.whoAmI();
	std::cout << "\n";

	DiamondTrap	henri("Henry");
	henri.whoAmI();
	henri = diego;
	henri.whoAmI();
	std::cout << "\n";

	return 0;
}
