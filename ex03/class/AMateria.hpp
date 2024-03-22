/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:59:33 by psalame           #+#    #+#             */
/*   Updated: 2024/03/22 10:06:19 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		const std::string	_type;

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		virtual ~AMateria(void);
		AMateria &operator=(const AMateria &copy);
	
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif