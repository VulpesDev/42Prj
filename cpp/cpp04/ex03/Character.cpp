/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:43:07 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/16 12:23:36 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string name )
{
	_name = name;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character( void )
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete(inventory[i]);
	}
}

Character::Character( const Character & other )
{
	*this = other;
}

Character&	Character::operator=( const Character & other )
{
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
		{
			inventory[i] = other.inventory[i];
		}
		_name = other.getName();
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			std::cout << "Equipted a " << m->getType() << " on slot " << i << std::endl;
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	inventory[idx]->use(target);
}
