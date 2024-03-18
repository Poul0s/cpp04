/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:20:00 by psalame           #+#    #+#             */
/*   Updated: 2024/03/18 16:45:45 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain {
	public:
		// constructor/destructor
		Brain(void);
		Brain(const Brain& copy);
		~Brain(void);

		// operator overload
		Brain&	operator=(const Brain& copy);

	private:
		std::string ideas[100];
};

#endif