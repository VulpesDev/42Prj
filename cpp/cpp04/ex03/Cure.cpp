/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:10:17 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/16 12:08:05 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void )
{
	type = "cure";
	std::cout << "Constructed a cure" << std::endl;
}

Cure::~Cure( void )
{
	std::cout << "Destructed a cure" << std::endl;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure*	Cure::clone( void ) const
{
	Cure*	result;

	result = new Cure(*this);
	return (result);
}
