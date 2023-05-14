/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:29:33 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/11 16:42:48 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( void )
{
	Animal* animals[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i%2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (size_t i = 0; i < 10; i++)
	{
		delete(animals[i]);
	}
	return (0);
}