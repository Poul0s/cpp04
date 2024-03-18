/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:47:11 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 15:06:12 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		// constructor/destructor
		Cat();
		Cat(const Cat& copy);
		~Cat();
		
		// operator overload
		Cat&	operator=(const Cat& copy);

		void	makeSound() const;
	
	private:
		Brain	*brain;
};

#endif