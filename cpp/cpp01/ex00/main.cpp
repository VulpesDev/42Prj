/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:49:12 by tvasilev          #+#    #+#             */
/*   Updated: 2023/06/20 12:55:31 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1("John");
	Zombie	*z2;
	z1.announce();
	z2 = newZombie("Tyler");
	z2->announce();
	delete (z2);
	randomChump("Rey");
	return (0);
}