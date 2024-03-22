/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:22:29 by psalame           #+#    #+#             */
/*   Updated: 2024/03/22 14:39:20 by psalame          ###   ########.fr       */
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
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = copy;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

// Operator oveverload
Character	&Character::operator=(const Character& copy)
{
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
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
			break ;
		}
		i++;
	}
	if (i == 4)
	{
		std::cout << "Could not equip materia " << m->getType() << "." << std::endl;
		delete m;
	}
}

void	Character::unequip(int idx)
{
	if (idx > 4 || idx < 0)
	{
		std::cout << "Inventory has only 4 slot : cannot unequip item out of inventory." << std::endl;
	}
	else if (this->_inventory[idx] != NULL)
	{
		this->_inventory[idx] = NULL;
	}

}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > 4 || idx < 0)
	{
		std::cout << "Inventory has only 4 slot : cannot use item out of inventory." << std::endl;
	}
	else if (this->_inventory[idx] != NULL)
	{
		this->_inventory[idx]->use(target);
	}
	else
		std::cout << "Cannot use materia of slot " << idx << " : slot is empty." << std::endl;
}

AMateria	*Character::getInventorySlot(int idx)
{
	return (this->_inventory[idx]);
}
