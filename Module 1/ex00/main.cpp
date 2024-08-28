/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <damian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:04:21 by ddania-c          #+#    #+#             */
/*   Updated: 2024/02/22 20:01:22 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );

void	randomChump( std::string name );

int	main() {
	Zombie	rumbleGore("RumbleGore");
	rumbleGore.announce();

	// Heap
	Zombie	*zombrero = newZombie("Zombrero");

	// Stack
	randomChump("ZomBurrito");

	delete zombrero;

	return (0);
}


