/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:16 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/20 12:41:38 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main( void ) {
	ClapTrap	tom("Tom");
	tom.attack("Max");
	tom.takeDamage(4);
	tom.beRepaired(2);
	std::cout << "\n";

	FragTrap	bob("Bob");
	bob.attack("Max");
	bob.takeDamage(20);
	bob.beRepaired(15);
	bob.highFivesGuys();
	std::cout << "\n";

	FragTrap	alex("Alex");
	alex = bob;
	alex.attack("Max");
	alex.takeDamage(35);
	alex.beRepaired(15);
	alex.takeDamage(-35);
	alex.beRepaired(-15);
	alex.highFivesGuys();
	std::cout << "\n";

	std::cout << "Tom hit points: " << tom.getHitPoints() << "\n";
	std::cout << "Bob hit points: " << bob.getHitPoints() << "\n";
	std::cout << "Alex hit points: " << alex.getHitPoints() << "\n\n";

	return 0;
}
