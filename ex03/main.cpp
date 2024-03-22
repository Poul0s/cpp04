/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:07:07 by psalame           #+#    #+#             */
/*   Updated: 2024/03/22 09:48:03 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"

void	test1(int &errNb)
{
	// test for character canonical form
	Character char1 ("abc");
	Character char2 (char1);

	std::cout << char1.getName() << std::endl;
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
	AMateria material1 = Ice();
	Ice material2 = material1;
	AMateria material3 = material1.clone();

	std::cout << material1.getType() << std::endl;
	std::cout << material2.getType() << std::endl;
	std::cout << material3.getType() << std::endl;
	
	if (material1.getType() != material2.getType() || material1.getType() != material3.getType())
	{
		std::cerr << "Test2 failed." << std::endl;
		errNb++;
	}
}

int	main(void)
{
	int	errNb = 0;
	
	test1(errNb);
	std::cout << std::endl;
	test2(errNb);

	return (errNb);
	// todo check avec github pour unit test
}
