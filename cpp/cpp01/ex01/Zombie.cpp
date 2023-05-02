/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:50:12 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/02 18:29:49 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	return ;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::Zombie(std::string name)
{
	setName(name);
}

Zombie::~Zombie( void )
{
	std::cout << this->name << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}