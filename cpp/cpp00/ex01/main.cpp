/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:52:40 by tvasilev          #+#    #+#             */
/*   Updated: 2023/06/20 11:02:14 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include<stdio.h>

int	main(void)
{
	PhoneBook	phonebook;
	string		input;

	while (1)
	{
		std::cout << "Enter command: ";
		while (input == "")
			std::getline(std::cin, input);
		if (!input.compare("ADD"))
		{
			phonebook.add();
		}
		else if (!input.compare("SEARCH"))
		{
			phonebook.search();
		}
		else if (!input.compare("EXIT"))
		{
			break ;
		}
		std::cout << std::endl;
		input.clear();
	}
	return 0;
}