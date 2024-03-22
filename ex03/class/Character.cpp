/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:22:29 by psalame           #+#    #+#             */
/*   Updated: 2024/03/21 18:17:02 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

// Constructor/destructor
Character::Character(void) : _name("NoName")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character::~Character(void)
{
}

// Operator oveverload
Character	&Character::operator=(const Character& copy)
{
	const_cast<std::string &> (this->_name) = copy.getName();
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

// Member functions
std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (i < 4)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Equiped materia " << m->getType() << " in the slot " << i << "." << std::endl;
			break ;
		}
	}
	if (i == 4)
		std::cout << "Could not equip materia " << m->getType() << "." << std::endl;
}

void	Character::unequip(int idx)
{
	if (this->_inventory[idx] != NULL)
	{
		std::cout << "Unequiped materia " << this->_inventory[idx] << " in slot " << idx << "." << std::endl;
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << "Inventory slot " << idx << "is empty." << std::endl;

}

void	Character::use(int idx, ICharacter& target)
{
	if (this->_inventory[idx] != NULL)
	{
		this->_inventory[idx]->use(target);
	}
	else
		std::cout << "Cannot use materia of slot " << idx << " : slot is empty." << std::endl;
}
