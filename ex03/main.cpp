/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:07:07 by psalame           #+#    #+#             */
/*   Updated: 2024/03/22 14:43:51 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void	test1(int &errNb)
{
	// test for character canonical form
	Character char1 ("abc");
	Ice		*ice = new Ice();
	char1.equip(ice);
	Character char2 (char1);

	std::cout << char1.getName() << " == ";
	std::cout << char2.getName() << std::endl;
	if (char1.getName() != char2.getName())
	{
		std::cerr << "Test1 failed." << std::endl;
		errNb++;
	}
}

void	test2(int &errNb)
{
	// test for materia canonical form
	Ice *material1 = new Ice();
	Ice material2 = *material1;
	Ice *material3 = (Ice *) material1->clone();

	std::cout << material1->getType() << " == ";
	std::cout << material2.getType() << " == ";
	std::cout << material3->getType() << std::endl;
	
	if (material1->getType() != material2.getType() || material1->getType() != material3->getType())
	{
		std::cerr << "Test2 failed." << std::endl;
		errNb++;
	}
	delete material1;
	delete material3;
}

void	test3(int &errNb)
{
	// test character inventory
	Character	*char1 = new Character("user1");
	Ice			*ice1 = new Ice();
	Ice			*ice2 = (Ice *) ice1->clone();
	Ice			*ice3 = (Ice *) ice1->clone();
	Ice			*ice4 = (Ice *) ice1->clone();
	Ice			*ice5 = (Ice *) ice1->clone();

	char1->unequip(999);
	char1->unequip(0);
	char1->equip(ice1);
	char1->equip(ice2);
	char1->equip(ice3);
	char1->equip(ice4);
	char1->equip(ice5);
	ice5 = new Ice(); // ice 5 deleted so create another

	if (char1->getInventorySlot(0) != ice1
		|| char1->getInventorySlot(1) != ice2
		|| char1->getInventorySlot(2) != ice3
		|| char1->getInventorySlot(3) != ice4)
	{
		std::cerr << "Test3 failed part A." << std::endl;
		errNb++;
	}
	char1->unequip(2);
	char1->equip(ice5);
	char1->equip(ice3);

	if (char1->getInventorySlot(0) != ice1
		|| char1->getInventorySlot(1) != ice2
		|| char1->getInventorySlot(2) != ice5
		|| char1->getInventorySlot(3) != ice4)
	{
		std::cerr << "Test3 failed part B." << std::endl;
		errNb++;
	}

	delete char1;
}

void	test4(int &errNb)
{
	// tests for use item
	Character	*char1 = new Character("user1");
	Character	*char2 = new Character("user2");
	Ice			*ice1 = new Ice();
	Cure		*cure1 = new Cure();

	char1->use(0, *char2);
	char1->equip(ice1);
	char1->equip(cure1);
	char1->use(999, *char2);
	char1->use(0, *char2);
	char1->use(1, *char2);
	char1->use(2, *char2);

	(void) errNb;
	
	delete char1;
	delete char2;
}

void test5(int &errNb)
{
	// tests for Materia Source
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp;
	tmp = src->createMateria("ice");
	if (tmp != NULL)
	{
		std::cerr << "Test5 failed part A." << std::endl;
		errNb++;
	}
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	tmp = src->createMateria("ice");
	if (tmp == NULL || tmp->getType() != "ice")
	{
		std::cerr << "Test5 failed part B." << std::endl;
		errNb++;
	}
	me->equip(tmp);
	tmp = src->createMateria("cure");
	if (tmp == NULL || tmp->getType() != "cure")
	{
		std::cerr << "Test5 failed part C." << std::endl;
		errNb++;
	}
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
}

void test6(int &errNb)
{
	// tests for Materia Source full learned
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	if (src->createMateria("cure") != NULL)
	{
		std::cerr << "Test6 failed." << std::endl;
		errNb++;
	}

	delete src;
}

void test_handler(void (*tst_fct) (int &), int &errNb)
{
	static int	tsti = 0;
	
	tsti++;
	try
	{
		(*tst_fct)(errNb);
	}
	catch (...)
	{
		std::cerr << "Test executed in pos " << tsti << " throw exception." << std::endl;
		errNb++;
	}
}

int	main(void)
{
	int	errNb = 0;

	test_handler(&test1, errNb);
	std::cout << std::endl;
	test_handler(&test2, errNb);
	std::cout << std::endl;
	test_handler(&test3, errNb);
	std::cout << std::endl;
	test_handler(&test4, errNb);
	std::cout << std::endl;
	test_handler(&test5, errNb);
	std::cout << std::endl;
	test_handler(&test6, errNb);

	return (errNb);
}
