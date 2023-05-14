/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:25:15 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/11 16:37:50 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain constructed" << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Brain destruction" << std::endl;
}

Brain::Brain( const Brain& other )
{
	std::cout << "Brain copied" << std::endl;
	*this = other;
}

Brain&	Brain::operator=( const Brain& other )
{
	if (this != &other)
		ideas = other.ideas;
	std::cout << "Brain assigned" << std::endl;
	return (*this);
}
