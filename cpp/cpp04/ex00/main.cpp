/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:29:33 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/11 12:24:59 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( void )
{
	Dog a1;
	// Animal a2;
	// Animal a3(a2);
	// Cat a4;
	// Dog a5;
	// Dog a6(a5);

	// a2 = a1;
	// a6 = a5;
	a1.makeSound();
	// a2.makeSound();
	// a3.makeSound();
	// a4.makeSound();
	// a5.makeSound();
	// a6.makeSound();
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete(i);
	delete(j);
	delete(meta);
	return (0);
}