/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:32:43 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/11 16:38:25 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound( void ) const
{
	std::cout << "*Meow*" << std::endl;
}

Cat::Cat( void )
{
	type = "cat";
	std::cout << "An animal has been created! " << type<< std::endl;
	_mozuk = new Brain();
}

Cat::~Cat( void )
{
	delete(_mozuk);
	std::cout << "Inherited destruct! " << type<< std::endl;
}