/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:54:04 by psalame           #+#    #+#             */
/*   Updated: 2024/03/22 14:44:02 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

// constructor/destructor
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
		this->_learned[i] = NULL;
	*this = copy;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_learned[i])
			delete this->_learned[i];
}

// operator overload
MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i])
			delete this->_learned[i];
		if (copy._learned[i])
			this->_learned[i] = copy._learned[i]->clone();
		else
			this->_learned[i] = NULL;
	}
	return (*this);
}

// member functions
void	MateriaSource::learnMateria(AMateria *materia)
{
	if (materia == NULL)
	{
		std::cout << "Cannot learn NULL Materia." << std::endl;
		return ;
	}
	int	i = 0;
	while (i < 4)
	{
		if (this->_learned[i] == NULL)
		{
			this->_learned[i] = materia;
			break ;
		}
		i++;
	}
	if (i == 4)
	{
		std::cout << "Cannot learn materia " << materia->getType() << std::endl;
		delete materia;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i] && this->_learned[i]->getType() == type)
			return (this->_learned[i]->clone());
	}
	return (NULL);
}