/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:04:21 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/18 14:38:42 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main() {

	int		N = 8;
	Zombie	*horde = zombieHorde(N, "StinkyZombie");

	for (int i = 0; i < N; i++) {
		std::cout << i + 1 << " ";
		horde[i].announce();
	}
	delete [] horde;

	return (0);
}
