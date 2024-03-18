/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:48:22 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 16:42:30 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "colors.h"

// constructor/destructor
Dog::Dog(void)
{
	std::cout << COLOR_BLUE << "Dog constructor called" << COLOR_RESET << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy)
{
	std::cout << COLOR_BLUE << COLOR_MODE_UNDERLINE << "Dog copy constructor called" << COLOR_RESET << std::endl;
	this->brain = new Brain();
	*this = copy;
}

Dog::~Dog(void)
{
	std::cout << COLOR_BLUE << COLOR_MODE_BOLD << "Dog destructor called" << COLOR_RESET << std::endl;
	delete this->brain;
}

// operator overload
Dog&	Dog::operator=(const Dog& copy)
{
	*((Animal *) this) = (Animal) copy;
	*(this->brain) = *copy.brain;
	return (*this);
}

// member functions
void	Dog::makeSound(void) const
{
	std::cout << "Ouaf!" << std::endl;
}
