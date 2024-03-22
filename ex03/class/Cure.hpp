/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:34:32 by psalame           #+#    #+#             */
/*   Updated: 2024/03/22 10:05:51 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		AMateria	*clone() const;
		void		use(ICharacter& target);
};

#endif