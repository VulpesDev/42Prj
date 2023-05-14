/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:22:10 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/12 13:52:08 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string	Animal::getType( void ) const
{
	return (type);
}

Animal::Animal( void )
{
	type = "animal";
	std::cout << "An animal has been created! " << type<< std::endl;
}

Animal::Animal( const Animal& other )
{
	std::cout << "An animal has been copied! " << type << " to " << other.type << std::endl;
	*this = other;
}

Animal&	Animal::operator=( const Animal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "An animal has been assigned! " << type << " to " << other.type << std::endl;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "Destructing a/an " << type << std::endl;
}
