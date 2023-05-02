/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:32:43 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/02 18:42:46 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int	main( void )
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	const char	*stringREF = str.data();

	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringPTR << std::endl;

	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << *stringPTR << std::endl;
	return (0);
}