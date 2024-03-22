/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:17:02 by psalame           #+#    #+#             */
/*   Updated: 2024/03/19 14:06:10 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include "colors.h"

AMateria::AMateria(std::string const & type) : _type(type)
{
}
AMateria::~AMateria(void)
{
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << COLOR_RED << "TODO" << COLOR_RESET << std::endl;
}