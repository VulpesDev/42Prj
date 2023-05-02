/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:51:07 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/02 18:22:43 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"
#include<memory>
#include<vector>


Zombie	*zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
        horde[i].announce();
    }
    return (horde);
}