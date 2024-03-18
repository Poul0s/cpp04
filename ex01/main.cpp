/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:11:25 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 16:45:42 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	
	const int	nbAnimals = 6;
	Animal	*animals[nbAnimals];

	for (int i = 0; i < nbAnimals / 2; i++)
		animals[i] = new Dog();
	for (int i = nbAnimals / 2; i < nbAnimals; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < nbAnimals; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}

	std::cout << std::endl;

	Dog dog = Dog();
	Dog dogCpy = Dog(dog);
	
	return (0);
}