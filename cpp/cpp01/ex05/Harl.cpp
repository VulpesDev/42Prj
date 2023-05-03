/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:16:29 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 14:39:28 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <functional>
#include <iostream>
#define COMPLAINTS_SIZE 4

void	Harl::debug( void )
{
	std::cout << "Completely fi?e, th?s p!@@@rogram is zz!!!zzz working" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "There is no 1000th McDonalds anymore!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "Stay away!" << std::endl;
}

void	Harl::error ( void )
{
	std::cout << "ERRRRRRRRRRRRRRROR, (kill me pls)" << std::endl;
}

void	Harl::complain( std::string level)
{
	int			found;
	std::string	complaints_str[COMPLAINTS_SIZE] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*complaints[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	found = 0;
	for (int i = 0; i < COMPLAINTS_SIZE; ++i)
	{
		if (complaints_str[i] == level)
		{
			(this->*complaints[i])();
			found = 1;
		}
	}
	if (!found)
		std::cerr << "Incorrect input!" << std::endl;
}
