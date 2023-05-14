/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:36:56 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/11 16:38:28 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::makeSound( void ) const
{
	std::cout << "*Bark*" << std::endl;
}

Dog::Dog( void )
{
	type = "dog";
	std::cout << "An animal has been created! " << type<< std::endl;
	_mozuk = new Brain();
}

Dog::~Dog( void )
{
	delete(_mozuk);
	std::cout << "Inherited destruct! " << type<< std::endl;
}