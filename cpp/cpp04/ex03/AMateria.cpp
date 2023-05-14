/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:00:07 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/12 15:49:18 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void )
{
	return ;
}

std::string const & AMateria::getType() const
{
	return (type);
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria constructed" << std::endl;
}

AMateria::AMateria(const AMateria & other)
{
	*this = other;
	std::cout << "AMateria copy constructor" << std::endl;
}

AMateria & AMateria::operator=(const AMateria & other)
{
	std::cout << "AMateria assigning" << std::endl;
	return (*this);
}

AMateria::~AMateria( void )
{
	std::cout << "AMateria destructed" << std::endl;
}

