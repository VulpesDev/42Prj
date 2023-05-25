/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:24:32 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/16 13:14:33 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (size_t i = 0; i < 4; i++)
		memory[i] = NULL;
	
}

MateriaSource::MateriaSource( const MateriaSource & other )
{
	*this = other;
}

MateriaSource&	MateriaSource::operator=( const MateriaSource & other )
{
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
			memory[i] = other.memory[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	for (size_t i = 0; i < 4; i++)
	{
		if (memory[i])
			delete(memory[i]);
	}
}

void		MateriaSource::learnMateria(AMateria* materia)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (memory[i] == NULL)
		{
			memory[i] = materia;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	if (type == "cure")
		return (new Cure());
	else if (type == "ice")
		return (new Ice());
	else
		return (NULL);
}

		