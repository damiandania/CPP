/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:16 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/19 20:43:13 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main( void ) {
	ClapTrap	tom("Tom");
	tom.attack("Max");
	tom.takeDamage(4);
	tom.beRepaired(2);
	std::cout << "\n";

	ClapTrap	copy(tom);
	copy.attack("Bob");
	copy.takeDamage(2);
	copy.beRepaired(-3);
	std::cout << "\n";

	ClapTrap	alex("Alex");
	alex = tom;
	alex.attack("Rick");
	alex.takeDamage(3);
	alex.beRepaired(5);

	std::cout << "\n";

	alex.attack("Rick");
	alex.attack("Rick");
	alex.attack("Rick");
	alex.attack("Rick");
	alex.attack("Rick");
	alex.attack("Rick");
	alex.attack("Rick");

	std::cout << "\n";

	std::cout << "Tom hit points: " << tom.getHitPoints() << "\n";
	std::cout << "Copy hit points: " << copy.getHitPoints() << "\n";
	std::cout << "Alex hit points: " << alex.getHitPoints() << "\n\n";

	return 0;
}
