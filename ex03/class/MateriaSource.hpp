/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:41:21 by psalame           #+#    #+#             */
/*   Updated: 2024/03/22 13:53:45 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		// constructor/destructor
		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		~MateriaSource(void);

		// operator overload
		MateriaSource	&operator=(const MateriaSource &copy);
		
		// member functions
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria	*_learned[4];
};

#endif