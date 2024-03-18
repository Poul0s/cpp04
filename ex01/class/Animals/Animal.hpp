/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:45:58 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 13:37:35 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		// constructor/destructor
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal();

		// operator overload
		Animal&	operator=(const Animal& copy);

		std::string	getType() const;
		virtual void	makeSound() const;

	protected:
		std::string type;
};

#endif