/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:17:02 by psalame           #+#    #+#             */
/*   Updated: 2024/03/22 10:09:49 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include "colors.h"

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	*this = copy;
}

AMateria::~AMateria(void)
{
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	(void) copy;
	return (*this);
}


std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "Default AMateria cannot be used!" << std::endl;
}