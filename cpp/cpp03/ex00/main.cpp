/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:19:23 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/08 12:27:26 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	kevin("Kevin");
	ClapTrap	robin("Robin");
	ClapTrap	percival("Percival");
	
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	robin.attack_target(&percival);
	robin = kevin;
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	kevin.attack_target(&robin);
	robin.attack_target(&percival);
	return (0);
}