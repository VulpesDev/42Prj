/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:16:17 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/15 16:23:47 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "Cure.hpp"
# include "Ice.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	memory[4];
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource & other );
		MateriaSource&	operator=( const MateriaSource & other );
		~MateriaSource( void );
		void		learnMateria(AMateria*) override; 
		AMateria*	createMateria(std::string const & type) override;
};

#endif