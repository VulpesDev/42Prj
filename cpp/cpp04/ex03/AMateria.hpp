/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:55:49 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/13 12:43:12 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

class	AMateria
{
	protected:
		std::string	type;
		
	public:
		AMateria( void );
		AMateria(std::string const & type);
		AMateria(const AMateria & other);
		AMateria & operator=(const AMateria & other);
		~AMateria( void );
		virtual std::string const & getType() const;
		virtual AMateria*	clone() const = 0;
		//virtual void		use(ICharacter& target);
};

#endif