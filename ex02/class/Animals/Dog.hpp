/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:47:11 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 16:46:08 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		// constructor/destructor
		Dog();
		Dog(const Dog& copy);
		~Dog();
	
		// overload operator
		Dog&	operator=(const Dog& copy);

		// member functions
		void	makeSound(void) const;
	
	private:
		Brain	*brain;
};

#endif