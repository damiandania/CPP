/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:16 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/20 12:42:54 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main( void ) {
	ClapTrap	tom("Tom");
	tom.attack("Max");
	tom.takeDamage(4);
	tom.beRepaired(2);
	std::cout << "\n";

	ScavTrap	bob("Bob");
	bob.attack("Tom");
	bob.takeDamage(20);
	bob.beRepaired(10);
	bob.guardGate();
	std::cout << "\n";

	ScavTrap	alex("Alex");
	alex = bob;
	alex.attack("Rick");
	bob.takeDamage(40);
	bob.beRepaired(5);
	bob.takeDamage(-1);
	bob.beRepaired(-5);
	alex.guardGate();
	std::cout << "\n";

	std::cout << "Tom hit points: " << tom.getHitPoints() << "\n";
	std::cout << "Bob hit points: " << bob.getHitPoints() << "\n";
	std::cout << "Alex hit points: " << alex.getHitPoints() << "\n\n";

	return 0;
}
