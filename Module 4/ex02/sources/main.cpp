/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:39:33 by damiandania       #+#    #+#             */
/*   Updated: 2024/03/21 15:15:41 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Brain.hpp"

#define NB_ARRAY 50

int	main(void)
{
	{
		// AAnimal AAnimal;
		// const AAnimal *	j = new Animal;
		const AAnimal *	j = new Dog();
		const AAnimal *	i = new Cat();

		j->makeSound();
		std::cout << j->getType() << '\n';
		i->makeSound();
		std::cout << j->getType() << '\n';

		const Dog* dogPtr = dynamic_cast<const Dog*>(j);
		dogPtr->getIdeas();

		const Cat* catPtr = dynamic_cast<const Cat*>(i);
		catPtr->getIdeas();

		delete j;
		delete i;
	}
	{
		AAnimal *array[NB_ARRAY];
		array[NB_ARRAY] = NULL;

		for (int i = 0; i < NB_ARRAY / 2; i++) {
			array[i] = new Dog();
			std::cout << i + 1 << " " << array[i]->getType() << "\n";
		}

		for (int i = NB_ARRAY / 2; i < NB_ARRAY; i++) {
			array[i] = new Cat();
			std::cout << i + 1 << " " << array[i]->getType() << "\n";
		}

		for (int i = 0; i < NB_ARRAY; i++) {
			delete array[i];
		}
	}
	{
		Cat	kitty;
		Cat	gato(kitty);

		std::cout << gato.getType() << " ";
		gato.makeSound();
		gato.getIdeas();

		Dog	doggy;
		Dog	perro(doggy);

		std::cout << perro.getType() << " ";
		perro.makeSound();
		perro.getIdeas();
	}
}
