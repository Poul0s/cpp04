/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:48:22 by psalame           #+#    #+#             */
/*   Updated: 2024/03/21 13:02:07 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "colors.h"

// constructor/destructor

Cat::Cat(void)
{
	std::cout << COLOR_YELLOW << "Cat constructor called" << COLOR_RESET << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy)
{
	std::cout << COLOR_YELLOW << COLOR_MODE_UNDERLINE << "Cat copy constructor called" << COLOR_RESET << std::endl;
	this->brain = new Brain();
	*this = copy;
}

Cat::~Cat(void)
{
	std::cout << COLOR_YELLOW << COLOR_MODE_BOLD << "Cat destructor called" << COLOR_RESET << std::endl;
	delete this->brain;
}

// operator overload
Cat&	Cat::operator=(const Cat& copy)
{
	*((Animal *) this) = (Animal &) copy;
	*(this->brain) = *copy.brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou!" << std::endl;
}
