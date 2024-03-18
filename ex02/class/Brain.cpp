/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:23:15 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 16:47:28 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "colors.h"
#include <iostream>

// constructor/destructor

Brain::Brain(void)
{
	std::cout << COLOR_MAGENTA << "Brain default constructor called" << COLOR_RESET << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << COLOR_MAGENTA << COLOR_MODE_UNDERLINE << "Brain copy constructor called" << COLOR_RESET << std::endl;
	*this = copy;
}

Brain::~Brain(void)
{
	std::cout << COLOR_MAGENTA << COLOR_MODE_BOLD << "Brain destructor called" << COLOR_RESET << std::endl;
}

// operator overload
Brain&	Brain::operator=(const Brain& copy)
{
	std::cout << COLOR_RED << "Brain copy overload called" << COLOR_RESET << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}