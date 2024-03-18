/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:49:43 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 14:34:13 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "colors.h"

// Constructor/Destructor

Animal::Animal()
{
	std::cout << COLOR_GREEN << "Animal constructor called" << COLOR_RESET << std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout << COLOR_GREEN << COLOR_MODE_UNDERLINE << "Animal copy constructor called" << COLOR_RESET << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << COLOR_GREEN << COLOR_MODE_BOLD << "Animal destructor called" << COLOR_RESET << std::endl;
}

// operator overload
Animal&	Animal::operator=(const Animal& copy)
{
	this->type = copy.type;
	return (*this);
}

// Member functions

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "*Animal sound*" << std::endl;
};
