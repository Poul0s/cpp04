/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:08:22 by psalame           #+#    #+#             */
/*   Updated: 2024/03/22 12:58:21 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		// Constructor/destructor
		Character(void);
		Character(const std::string &name);
		Character(const Character &copy);
		~Character(void);

		// Operator oveverload
		Character	&operator=(const Character& copy);

		// Member functions
		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

		// tests fct
		AMateria			*getInventorySlot(int idx);

	private:
		AMateria			*_inventory[4];
		std::string			_name;
};

#endif