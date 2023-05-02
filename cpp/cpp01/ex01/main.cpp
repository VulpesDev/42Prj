/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:03:42 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/02 18:29:43 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <unistd.h>

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(10, "Many");
	delete[] horde;
	return (0);
}