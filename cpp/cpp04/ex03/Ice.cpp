/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:43:48 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/16 12:08:00 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void )
{
	type = "ice";
	std::cout << "Constructed an ice" << std::endl;
}

Ice::~Ice( void )
{
	std::cout << "Destructed an ice" << std::endl;
}

Ice*	Ice::clone( void ) const
{
	Ice*	result;

	result = new Ice(*this);
	return (result);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}