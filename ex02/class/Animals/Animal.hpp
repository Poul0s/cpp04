/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:45:58 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 16:54:05 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	protected:
		// constructor/destructor
		Animal();

		std::string	getType() const;
		virtual void	makeSound() const;

		std::string type;

	public:
		Animal(const Animal& copy);
		virtual ~Animal();

		// operator overload
		Animal&	operator=(const Animal& copy);

};

#endif