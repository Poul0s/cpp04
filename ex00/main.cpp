/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:51:32 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 13:55:56 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	typesTests()
{
	std::cout << "/*  Types tests  */" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const Animal* k = i;
	k->makeSound();

	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;
}

void	castTests()
{
	std::cout << "/*  Cast tests  */" << std::endl;

	Cat cat;
	Animal animal = cat;
	
	std::cout << std::endl;
	std::cout << cat.getType() << " " << std::endl;
	std::cout << animal.getType() << " " << std::endl;
	cat.makeSound();
	animal.makeSound(); //will output the animal sound!
	std::cout << std::endl;
}

void	wrongTests()
{
	std::cout << "/*  Wrong tests  */" << std::endl;
	
	const WrongAnimal* wrongAnimal = new WrongCat();
	std::cout << std::endl;
	std::cout << wrongAnimal->getType() << " " << std::endl;
	wrongAnimal->makeSound();

	std::cout << std::endl;
	delete wrongAnimal;
}

int	main(void)
{
	typesTests();
	std::cout << std::endl << std::endl;
	castTests();
	std::cout << std::endl << std::endl;
	wrongTests();

	return 0;
}